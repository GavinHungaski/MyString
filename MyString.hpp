#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream> // ostream

class MyString {
    public:
        // Constructor
        MyString(const char *value = "");

        // Copy Constructor
        MyString(const MyString &obj);

        // Move Constructor
        MyString(MyString &&obj);

        // = Assignment Overloader
        MyString &operator= (const MyString &obj);

        // = Assignment Move Overloader
        MyString &operator= (MyString &&obj);
        
        // += Overloader
        MyString &operator+= (const MyString &obj);

        // Index Overloader
        char &operator[](int i);

        // Returns Buffer as a Reference (for testing)
        char *c_str();

        // + Overloader
        friend MyString operator+ (const MyString &a, const MyString &b);

        // cout Overloader
        friend std::ostream &operator<< (std::ostream &os, const MyString &obj);

        // Destructor
        ~MyString();

    private:
        int buffer_size; 
        char* buffer;
};

#endif