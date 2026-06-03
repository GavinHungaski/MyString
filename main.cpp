#include <iostream> // cout
#include "MyString.hpp"

using namespace std;

int main() {
    MyString name = "Henry";
    // name = "Gavin";                 TODO: recreate the assignment overloader so this now prints Gavin
    cout << name << endl;

    return 0;
};
