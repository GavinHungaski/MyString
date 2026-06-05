---
title: DEVLOG
date: 2026-05-28
---

<h1>DevLog</h1>

Developing a MyString class from scratch to replace / compare to the `std::string` class that exists.<br /><br />

<h3>GOALS:</h3>

- A heap-allocated char buffer with manual memory management (constructor, destructor, copy constructor, move constructor, copy/move assignment — the Rule of Five)
- Core methods: `append`, `insert`, `find`, `substring`, `split`, `trim`
- `operator+`, `operator==`, `operator[]` overloads
- An iterator so you can use range-based for loops on it
- A test suite to validate all previous goals<br /><br />

<h3>NOTES:</h3>

**2026-05-28**

- I started with a basic class structure with a constructor, destructor.
- I attempted to implement an assignment overloader and ran into a double-free bug, will return to this

**2026-05-30**

- Created and made first commit to the public GitHub repo

**2026-06-03**

- I deconstructed the single monolithic file MyString.cpp into the subsequent header and definition files that a  modern C++ project would expect
- Added a Makefile and wrote the command structure to compile and clean the project directory

**2026-06-05**

- Added a move constructor and a move assignment overloader, also added c_str function that returns the buffer to help with testing
- Added an index overloader that allows for python like indexing with negative numbers
- Created and integrated a test suite to check over each new feature