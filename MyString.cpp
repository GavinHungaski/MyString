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


// cout Overloader
ostream &operator<<(ostream &os, const MyString &obj) {
    os << obj.buffer;
    return os;
};


// Destructor
MyString::~MyString() {
    delete[] buffer;
};
