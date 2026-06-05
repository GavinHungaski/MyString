#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream> // ostream

class MyString {
    public:
        // Constructor
        MyString(const char *value = "");

        // = Overloader
        MyString &operator= (const MyString &obj);

        // += Overloader
        MyString &operator+= (const MyString &obj);

        // cout Overloader
        friend std::ostream &operator<< (std::ostream &os, const MyString &obj);

        // Destructor
        ~MyString();

    private:
        int buffer_size; 
        char* buffer;
};

#endif