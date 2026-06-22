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

    MyString eq1 = "Hello";
    MyString eq2 = "Hello";
    MyString eq3 = "World";
    MyString eq4 = "Hellz";
    test(
        "true",
        (eq1 == eq2) ? "true" : "false",
        "Equality Operator (equal)"
    );
    test(
        "false",
        (eq1 == eq3) ? "true" : "false",
        "Equality Operator (not equal)"
    );
    test(
        "false",
        (eq1 == eq4) ? "true" : "false",
        "Equality Operator (same length, different content)"
    );

    MyString plus_a = "Hello";
    MyString plus_b = " World";
    MyString plus_result = plus_a + plus_b;
    test(
        "Hello World",
        plus_result.c_str(),
        "operator+"
    );
    test(
        "Hello",
        plus_a.c_str(),
        "operator+ (left operand unchanged)"
    );

    MyString plus_eq = "Hello";
    plus_eq += " World";
    test(
        "Hello World",
        plus_eq.c_str(),
        "operator+="
    );

    MyString idx = "Hello";
    char idx_buf[2] = {idx[0], '\0'};
    test(
        "H",
        idx_buf,
        "operator[] (first char)"
    );
    char idx_last_buf[2] = {idx[4], '\0'};
    test(
        "o",
        idx_last_buf,
        "operator[] (last char)"
    );
    char idx_neg_buf[2] = {idx[-1], '\0'};
    test(
        "o",
        idx_neg_buf,
        "operator[] (negative index -1)"
    );
    char idx_neg2_buf[2] = {idx[-5], '\0'};
    test(
        "H",
        idx_neg2_buf,
        "operator[] (negative index -5)"
    );

    MyString app = "Hello";
    app.append(" World");
    test(
        "Hello World",
        app.c_str(),
        "Append"
    );

    MyString ins = "Helo";
    ins.insert(3, "l");
    test(
        "Hello",
        ins.c_str(),
        "Insert (middle)"
    );

    MyString ins_front = "World";
    ins_front.insert(0, "Hello ");
    test(
        "Hello World",
        ins_front.c_str(),
        "Insert (front)"
    );

    MyString ins_end = "Hello";
    ins_end.insert(5, " World");
    test(
        "Hello World",
        ins_end.c_str(),
        "Insert (end)"
    );

    MyString src = "Hello World";
    test(
        "6",
        (src.find("World") == 6) ? "6" : "fail",
        "Find"
    );
    test(
        "0",
        (src.find("Hello") == 0) ? "0" : "fail",
        "Find (at index 0)"
    );
    test(
        "-1",
        (src.find("xyz") == -1) ? "-1" : "fail",
        "Find (not found)"
    );

    MyString sub = "Hello World";
    test(
        "World",
        sub.substring(6, 5).c_str(),
        "Substring (middle to end)"
    );
    test(
        "Hello",
        sub.substring(0, 5).c_str(),
        "Substring (from start)"
    );
    test(
        "Hello World",
        sub.substring(0, 11).c_str(),
        "Substring (full string)"
    );

    MyString splitStr = "one,two,three";
    int count = 0;
    MyString *parts = splitStr.split(",", count);
    test("3", (count == 3) ? "3" : "fail", "Split (count)");
    test("one", parts[0].c_str(), "Split (part 1)");
    test("two", parts[1].c_str(), "Split (part 2)");
    test("three", parts[2].c_str(), "Split (part 3)");
    delete[] parts;

    MyString splitNone = "hello";
    int splitNoneCount = 0;
    MyString *splitNoneParts = splitNone.split(",", splitNoneCount);
    test("1", (splitNoneCount == 1) ? "1" : "fail", "Split (no delimiter found, count)");
    test("hello", splitNoneParts[0].c_str(), "Split (no delimiter found, part 1)");
    delete[] splitNoneParts;

    MyString trimBoth = "  Hello  ";
    trimBoth.trim();
    test(
        "Hello",
        trimBoth.c_str(),
        "Trim (both sides)"
    );

    MyString trimLeft = "  Hello";
    trimLeft.trim();
    test(
        "Hello",
        trimLeft.c_str(),
        "Trim (leading only)"
    );

    MyString trimRight = "Hello  ";
    trimRight.trim();
    test(
        "Hello",
        trimRight.c_str(),
        "Trim (trailing only)"
    );

    MyString trimNone = "Hello";
    trimNone.trim();
    test(
        "Hello",
        trimNone.c_str(),
        "Trim (no whitespace)"
    );

    MyString iterStr = "Hi";
    MyString iterResult = "";
    for (char c : iterStr) {
        char buf[2] = {c, '\0'};
        iterResult.append(buf);
    }
    test(
        "Hi",
        iterResult.c_str(),
        "Iterator"
    );

    cout << endl << "=========================================" << endl;
    cout << "Testing Concluded." << endl;
}
