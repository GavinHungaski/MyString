#include <iostream> // cout
#include <cstring>  // strcmp
#include "test.hpp"
#include "MyString.hpp"

using namespace std;

void test(const char *expected, const char *actual, const char *name = "test") {
    if (strcmp(expected, actual) == 0) {
        cout << "[PASS] " << name << ": expected " << expected << ", got " << actual << endl;
    } else {
        cout << "[FAIL] "  << name << ": expected " << expected << ", got " << actual << endl;
    }
}

void test_script() {
    cout << "Beginning Testing . . ." << endl;
    cout << "=========================================" << endl << endl;

    MyString name = "Gavin";
    test(
        "Gavin",
        name.c_str(),
        "Constructor"
    );

    MyString copy_constructor = name;
    test(
        "Gavin",
        copy_constructor.c_str(),
        "Copy Constructor (Step 1)"
    );
    test(
        "Gavin",
        name.c_str(),
        "Copy Constructor (Step 2)"
    );

    MyString move_constructor = move(name);
    test(
        "Gavin",
        move_constructor.c_str(),
        "Move Constructor (Step 1)"
    );
    test(
        "",
        name.c_str(),
        "Move Constructor (Step 2)"
    );

    name = "Henry";
    test(
        "Henry",
        name.c_str(),
        "Assignment Operator"
    );
    
    MyString move_assignment_operator = "Bary";
    name = move(move_assignment_operator);
    test(
        "Bary",
        name.c_str(),
        "Move Assignment Operator (Step 1)"
    );
    test(
        "",
        move_assignment_operator.c_str(),
        "Move Assignment Operator  (Step 2)"
    );
    
    MyString temp3 = "Gary";
    name = temp3;
    test(
        "Gary",
        name.c_str(),
        "Copy Assignment Operator"
    );

    cout << endl << "=========================================" << endl;
    cout << "Testing Concluded." << endl;
}
