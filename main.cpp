#include <iostream> // cout
#include "MyString.hpp"

using namespace std;

int main() {
    MyString name = "Henry";
    cout << name << endl;

    name = "Gavin";
    cout << name << endl;

    MyString name2 = "David";
    name = name2;
    cout << name << endl;

    return 0;
};
