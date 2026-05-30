#include <iostream> // cout
#include <cstring> // strlen

using namespace std;


class MyString {
    public:
        // Constructor
        MyString(const char *value = "") {
            buffer_size = strlen(value);
            buffer = new char[buffer_size + 1]{};   // Initialize the character buffer with all 0 values, leave space for null terminator '\n'

            if (sizeof(value) > 0) {
                for(int i=0; i < strlen(value); i++) {
                    buffer[i] = value[i];
                };
            };
        };

        // cout Overloader Reference
        friend ostream &operator<<(ostream &os, const MyString &obj);

        // Destructor
        ~MyString() {
            delete[] buffer;
        };

    private:
        int buffer_size; 
        char* buffer;
};


// cout Overloader Definition
ostream &operator<<(ostream &os, const MyString &obj) {
    os << obj.buffer;
    return os;
};


int main() {
    MyString name = "Henry";
    // name = "Gavin";                 TODO: recreate the assignment overloader so this now prints Gavin
    cout << name << endl;

    return 0;
};
