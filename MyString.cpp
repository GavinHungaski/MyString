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
    if (i >= buffer_size || i < -buffer_size) {
        cout << "String index out of bound, exiting" << endl;
        exit(0);
    }
    if (i < 0) {
        return buffer[buffer_size + i];
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

// == Overloader
bool operator== (const MyString &a, const MyString &b) {
    if (a.buffer_size != b.buffer_size) return false;
    for (int i = 0; i < a.buffer_size; i++) {
        if (a.buffer[i] != b.buffer[i]) return false;
    }
    return true;
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

void MyString::append(const MyString &obj) {
    *this += obj;
}

void MyString::insert(int index, const MyString &obj) {
    if (index < 0) index = 0;
    if (index > buffer_size) index = buffer_size;
    int new_size = buffer_size + obj.buffer_size;
    char *temp_buffer = new char[new_size + 1]{};
    for (int i = 0; i < index; i++) {
        temp_buffer[i] = buffer[i];
    }
    for (int i = 0; i < obj.buffer_size; i++) {
        temp_buffer[index + i] = obj.buffer[i];
    }
    for (int i = index; i < buffer_size; i++) {
        temp_buffer[obj.buffer_size + i] = buffer[i];
    }
    delete[] buffer;
    buffer = temp_buffer;
    buffer_size = new_size;
}

int MyString::find(const MyString &obj) const {
    if (obj.buffer_size == 0) return 0;
    for (int i = 0; i <= buffer_size - obj.buffer_size; i++) {
        bool match = true;
        for (int j = 0; j < obj.buffer_size; j++) {
            if (buffer[i + j] != obj.buffer[j]) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }
    return -1;
}

MyString MyString::substring(int start, int length) const {
    if (start < 0) start = 0;
    if (start >= buffer_size) return MyString("");
    if (start + length > buffer_size) length = buffer_size - start;
    char *temp = new char[length + 1]{};
    for (int i = 0; i < length; i++) {
        temp[i] = buffer[start + i];
    }
    MyString result(temp);
    delete[] temp;
    return result;
}

MyString *MyString::split(const MyString &delim, int &count) const {
    count = 0;
    if (delim.buffer_size == 0) {
        count = 1;
        MyString *result = new MyString[1];
        result[0] = *this;
        return result;
    }
    int pos = 0;
    while (pos <= buffer_size - delim.buffer_size) {
        bool match = true;
        for (int j = 0; j < delim.buffer_size; j++) {
            if (buffer[pos + j] != delim.buffer[j]) { match = false; break; }
        }
        if (match) { count++; pos += delim.buffer_size; } else { pos++; }
    }
    count++;
    MyString *result = new MyString[count];
    int idx = 0;
    int start = 0;
    pos = 0;
    while (pos <= buffer_size - delim.buffer_size) {
        bool match = true;
        for (int j = 0; j < delim.buffer_size; j++) {
            if (buffer[pos + j] != delim.buffer[j]) { match = false; break; }
        }
        if (match) {
            result[idx++] = substring(start, pos - start);
            pos += delim.buffer_size;
            start = pos;
        } else {
            pos++;
        }
    }
    result[idx] = substring(start, buffer_size - start);
    return result;
}

void MyString::trim() {
    int start = 0;
    while (start < buffer_size && (buffer[start] == ' ' || buffer[start] == '\t' || buffer[start] == '\n' || buffer[start] == '\r')) {
        start++;
    }
    int end = buffer_size - 1;
    while (end >= start && (buffer[end] == ' ' || buffer[end] == '\t' || buffer[end] == '\n' || buffer[end] == '\r')) {
        end--;
    }
    int new_size = end - start + 1;
    if (new_size < 0) new_size = 0;
    char *temp_buffer = new char[new_size + 1]{};
    for (int i = 0; i < new_size; i++) {
        temp_buffer[i] = buffer[start + i];
    }
    delete[] buffer;
    buffer = temp_buffer;
    buffer_size = new_size;
}
