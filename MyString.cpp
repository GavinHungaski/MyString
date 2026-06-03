#include <cstring> // strlen
#include "MyString.hpp"

using namespace std;

// Constructor
MyString::MyString(const char *value) {
    buffer_size = strlen(value);
    buffer = new char[buffer_size + 1]{};   // Initialize the character buffer with all 0 values, leave space for null terminator '\0'

    if (buffer_size > 0) {
        for(int i=0; i < buffer_size; i++) {
            buffer[i] = value[i];
        };
    };
};

// Destructor
MyString::~MyString() {
    delete[] buffer;
};


// cout Overloader
ostream &operator<<(ostream &os, const MyString &obj) {
    os << obj.buffer;
    return os;
};
