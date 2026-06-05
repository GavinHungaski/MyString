#include <cstring> // strlen
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

// = Overloader
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
