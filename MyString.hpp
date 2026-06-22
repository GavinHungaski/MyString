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

        // == Overloader
        friend bool operator== (const MyString &a, const MyString &b);

        // cout Overloader
        friend std::ostream &operator<< (std::ostream &os, const MyString &obj);

        // Destructor
        ~MyString();

        void append(const MyString &obj);
        void insert(int index, const MyString &obj);
        int find(const MyString &obj) const;
        MyString substring(int start, int length) const;
        MyString *split(const MyString &delim, int &count) const;
        void trim();

        struct Iterator {
            char *ptr;
            char &operator*() { return *ptr; }
            Iterator &operator++() { ++ptr; return *this; }
            bool operator!=(const Iterator &other) const { return ptr != other.ptr; }
        };

        Iterator begin() { return Iterator{buffer}; }
        Iterator end() { return Iterator{buffer + buffer_size}; }

    private:
        int buffer_size; 
        char* buffer;
};

#endif