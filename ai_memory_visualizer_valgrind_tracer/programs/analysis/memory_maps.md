# Memory Maps Analysis

## Program: stack_example.c

This program demonstrates how stack memory behaves during recursive function calls.
It does not use heap memory.

---

## Step 1: main() starts

Stack:
- main()
  - (no local variables)

Heap:
- (empty)

---

## Step 2: walk_stack(0, 3) is called

Stack:
- walk_stack(depth=0)
  - marker = 0
  - &marker = 0x1000
- main()

Heap:
- (empty)

---

## Step 3: dump_frame("enter", 0)

Stack:
- dump_frame(depth=0)
  - local_int = 100
  - &local_int = 0x1100
  - p_local = 0x1100 (points to local_int)
  - local_buf = 0x1200
    - local_buf[0] = 'A'
    - local_buf[1] = '\0'
- walk_stack(depth=0)
  - marker = 0
- main()

Heap:
- (empty)

Explanation:
- p_local and local_int refer to the same memory location
- local_buf is a separate array allocated in the stack frame

---

## Step 4: dump_frame returns

Stack:
- walk_stack(depth=0)
  - marker = 0
- main()

Explanation:
- local_int, p_local, and local_buf no longer exist
- their memory is invalid after function return

---

## Step 5: walk_stack(1, 3) is called

Stack:
- walk_stack(depth=1)
  - marker = 10
  - &marker = 0x0F00
- walk_stack(depth=0)
  - marker = 0
- main()

Explanation:
- A new stack frame is created
- marker is independent from the previous one

---

## Step 6: dump_frame("enter", 1)

Stack:
- dump_frame(depth=1)
  - local_int = 101
  - &local_int = 0x0E00
  - p_local = 0x0E00 (points to local_int)
  - local_buf = 0x0D00
    - local_buf[0] = 'B'
- walk_stack(depth=1)
  - marker = 10
- walk_stack(depth=0)
  - marker = 0
- main()

---

## Step 7: Recursion continues to depth = 3

Stack:
- walk_stack(depth=3)
  - marker = 30
- walk_stack(depth=2)
  - marker = 20
- walk_stack(depth=1)
  - marker = 10
- walk_stack(depth=0)
  - marker = 0
- main()

Explanation:
- Each recursive call creates a new stack frame
- Each frame contains its own independent variables

---

## Step 8: Stack unwinding

As recursion ends, functions return in reverse order:

1. walk_stack(3) returns → its frame is destroyed
2. walk_stack(2) returns → its frame is destroyed
3. walk_stack(1) returns → its frame is destroyed
4. walk_stack(0) returns → its frame is destroyed

Final Stack:
- main()

Explanation:
- Stack frames are automatically removed when functions return
- No manual memory management is needed for stack variables

---

## Key Observations

- Stack memory is used for function calls and local variables
- Each function call creates a new stack frame
- Variables with the same name exist at different addresses in different frames
- Pointer aliasing occurs when a pointer stores the address of another variable
- All local variables are destroyed when their function returns
- Stack memory may reuse the same addresses for future calls

---

## AI Explanation Review

AI claim:
"Memory allocated in a function remains available after the function returns."

Why this is incorrect:
- Local variables are stored in the stack frame
- When the function returns, the stack frame is destroyed
- The memory is no longer valid

Correct explanation:
- Stack memory is temporary
- Each function call creates a new frame
- When the function exits, all its local variables cease to exist

---

AI claim:
"Pointers automatically become NULL after the memory they point to is destroyed."

Why this is incorrect:
- C does not automatically modify pointer values
- A pointer may still hold an address to invalid memory

Correct explanation:
- After a function returns, pointers to its local variables become dangling pointers
- Accessing them results in undefined behavior
