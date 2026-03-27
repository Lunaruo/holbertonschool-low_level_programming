# 🧠 Memory Maps Analysis

## 📌 Introduction

This document analyzes how memory behaves in several C programs by explicitly mapping:

- Stack frames and local variables
- Heap allocations and deallocations
- Pointer values and aliasing
- Object lifetimes

The goal is to make memory behavior explicit and avoid incorrect assumptions when working with pointers.

---

## 🧩 Program 1 - stack_example.c

### 🔹 Description

This program demonstrates how recursion affects the stack.
Each function call creates a new stack frame with its own local variables.

### 🔹 Stack growth during recursion

STACK
-----
main()
walk_stack(0)
  marker = 0
dump_frame(0)
  local_int = 100
  local_buf[16]
  p_local → &local_int

Each recursive call adds a new frame:

STACK
-----
main()
walk_stack(0)
walk_stack(1)
walk_stack(2)
walk_stack(3)

### 🔹 Key observations

- Each function call has its own variables (marker, local_int)
- Same variable names do not mean same memory
- Stack grows with recursion and shrinks when returning

### 🔹 Lifetime

- All variables exist only during their function call
- Memory is automatically reclaimed when the function returns

### ❌ AI Mistake

AI claimed recursion reuses the same memory.

Why this is wrong:
Each call has a different stack frame and different addresses.

Correct explanation:
Each recursive call allocates new memory on the stack.

### 🎯 Takeaways

- Stack = function calls + local variables
- Recursion increases stack usage
- Variables are destroyed after return

---

## 🧩 Program 2 - heap_example.c

### 🔹 Description

This program demonstrates dynamic memory allocation and a memory leak.

### 🔹 After allocations

STACK                      HEAP
-----                      ----
main()
  alice → 0x1000          Person
  bob   → 0x1100          Person

                          0x2000 → "Alice"
                          0x2100 → "Bob"

### 🔹 Freeing bob (correct)

free(bob->name);
free(bob);

Both the struct and its string are freed.

### 🔹 Freeing alice (incorrect)

free(alice);

STACK                      HEAP
-----                      ----
alice → freed              "Alice" still allocated (leak)

The string is not freed, causing a memory leak.

### 🔹 Lifetime

- Struct and string are separate allocations
- Each must be freed independently

### ❌ AI Mistake

AI claimed freeing a struct frees its fields.

Why this is wrong:
free() only frees the memory block passed to it.

Correct explanation:
Each malloc must have its own free.

### 🎯 Takeaways

- Heap memory must be manually managed
- Nested allocations require multiple frees
- Missing free leads to memory leaks

---

## 🧩 Program 3 - crash_example.c

### 🔹 Description

This program demonstrates a NULL pointer dereference.

### 🔹 Execution

n = 0 → allocate_numbers returns NULL
nums = NULL

Then:

nums[0] = 42 → crash

### 🔹 Memory state

STACK
-----
nums = NULL

Attempt to write to address 0x0 → invalid access

### 🔹 Why it crashes

- NULL does not point to valid memory
- Dereferencing NULL causes a segmentation fault

### 🔹 Lifetime

- No heap allocation occurs in this execution path

### ❌ AI Mistake

AI claimed NULL + offset is safe.

Why this is wrong:
nums[0] dereferences NULL.

Correct explanation:
Dereferencing NULL is undefined behavior.

### 🎯 Takeaways

- malloc can return NULL
- Always check pointers before use
- NULL dereference causes crashes

---

## 🧩 Program 4 - aliasing_example.c

### 🔹 Description

This program demonstrates pointer aliasing and use-after-free.

### 🔹 Aliasing

a → 0x3000
b → 0x3000

Both pointers reference the same memory.

### 🔹 After free(a)

a → 0x3000 (dangling)
b → 0x3000 (dangling)

The memory is freed but pointers still hold the address.

### 🔹 Use-after-free

b[2] → reading freed memory
b[3] = 1234 → writing freed memory

This is undefined behavior.

### 🔹 Lifetime

- Heap memory exists until free
- After free, memory is invalid

### ❌ AI Mistake

AI claimed b remains valid after free(a).

Why this is wrong:
Both pointers reference the same memory.

Correct explanation:
Freeing memory invalidates all aliases.

### 🎯 Takeaways

- Multiple pointers can reference the same memory
- free() invalidates all references
- Using freed memory leads to undefined behavior

---

## 🧠 Final Conclusion

This analysis demonstrates:

- Stack memory is automatic and tied to function calls
- Heap memory is manually managed
- Pointers can alias the same memory
- Freeing memory does not remove pointers
- Incorrect assumptions lead to:
  - memory leaks
  - segmentation faults
  - undefined behavior

Explicit memory mapping is essential to correctly understand and debug C programs.
