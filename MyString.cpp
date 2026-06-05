#include <cstring> // strlen
#include <iostream> // cout
#include "MyString.hpp"

using namespace std;

// Constructor
MyString::MyString(const char *value) {
    buffer_size = strlen(value);
    buffer = new char[buffer_size + 1]{};

    if (buffer_size > 0) {
        for(int i=0; i < buffer_size; i++) {
            buffer[i] = value[i];
        };
    };
};

// Copy Constructor
MyString::MyString(const MyString &obj) {
    buffer_size = obj.buffer_size;
    buffer = new char[buffer_size + 1]{};
    for (int i=0; i < buffer_size; i++) {
        buffer[i] = obj.buffer[i];
    }
}

// Move Contrusctor
MyString::MyString(MyString &&obj) {
    buffer_size = obj.buffer_size;
    buffer = obj.buffer;
    obj.buffer = nullptr;
    obj.buffer_size = 0;
}

// = Assignment Overloader
MyString &MyString::operator= (const MyString &obj) {
    if (this != &obj) {
        char *temp_buffer = new char[obj.buffer_size + 1]{};
        for (int i=0; i < obj.buffer_size; i++) {
            temp_buffer[i] = obj.buffer[i];
        }

        delete[] buffer;
        buffer = temp_buffer;
        buffer_size = obj.buffer_size;
    }
    return *this;
}

// = Assignment Move Overloader
MyString &MyString::operator= (MyString &&obj) {
    if (this != &obj) {
        delete[] buffer;
        buffer = obj.buffer;
        buffer_size = obj.buffer_size;
        obj.buffer = nullptr;
        obj.buffer_size = 0;
    }
    return *this;
}

// += Overloader
MyString &MyString::operator+= (const MyString &obj) {
    int temp_buffer_size = obj.buffer_size + buffer_size;
    char *temp_buffer = new char[temp_buffer_size + 1]{};

    for (int i=0; i < buffer_size; i++)  {
        temp_buffer[i] = buffer[i];
    }
    
    for (int i=buffer_size; i < temp_buffer_size; i++) {
        temp_buffer[i] = obj.buffer[i - buffer_size];
    }

    delete[] buffer;
    buffer = temp_buffer;
    buffer_size = temp_buffer_size;
    return *this;
}

// Index Overloader
char &MyString::operator[](int i) {
    int text_length = buffer_size - 1;
    if (i >= text_length || i < -text_length) {
        cout << "String index out of bound, exiting" << endl;
        exit(0);
    }
    if (i < 0) {
        return buffer[text_length + i + 1];
    } else {
        return buffer[i];
    }
}

// Returns Buffer as a Reference (for testing)
char *MyString::c_str() {
    return const_cast<char*>(buffer == NULL? "" : buffer);
}

// + Overloader
MyString operator+ (const MyString &a, const MyString &b) {
    MyString temp = a;
    temp += b;
    return temp;
}

// cout Overloader
ostream &operator<<(ostream &os, const MyString &obj) {
    os << obj.buffer;
    return os;
};

// Destructor
MyString::~MyString() {
    delete[] buffer;
};
