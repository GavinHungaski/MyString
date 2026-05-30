---
title: DEVLOG
date: 2026-05-28
---

<h1>DevLog</h1>

Developing a MyString class from scratch to replace / compare to the std::string class that exists.<br /><br />

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