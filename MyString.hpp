#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream> // ostream

class MyString {
    public:
        // Constructor
        MyString(const char *value = "");

        // cout Overloader Reference
        friend std::ostream &operator<<(std::ostream &os, const MyString &obj);

        // Destructor
        ~MyString();

    private:
        int buffer_size; 
        char* buffer;
};

#endif