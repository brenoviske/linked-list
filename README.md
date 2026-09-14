# Linked List in C with Memory Arena Allocator

A simple implementation of a **linked list in C** using a custom **memory arena allocator**.

This project was created to explore how dynamic data structures work at a lower level in C, with particular focus on **pointers, dynamic memory allocation, structures, and manual memory management**.

## 📌 Overview

A linked list is a dynamic data structure composed of individual elements called **nodes**.

Each node contains:

1. The data stored in that node.
2. A pointer to the **next node** in the list.

Conceptually, the structure looks like this:

```text
[ Data | Next ] -> [ Data | Next ] -> [ Data | Next ] -> NULL
```

Unlike an array, the nodes do not need to be stored next to each other in memory. Each node simply keeps the address of the next node.

In C, this can be represented using a structure such as:

```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```

The `next` pointer is what connects one node to another.

---

## 🧱 How the Linked List Works

The linked list starts with a pointer to the first node, commonly called `head`.

For example:

```c
Node *head = NULL;
```

When a node is created, memory is allocated for it and its `next` pointer can be used to connect it to another node.

For example:

```text
head
 ↓
[10 | •] ----> [20 | •] ----> [30 | NULL]
```

The first node points to the second node, the second points to the third, and the final node points to `NULL`, indicating the end of the list.

To traverse the list, we follow these pointers:

```c
Node *current = head;

while (current != NULL) {
    printf("%d\n", current->data);
    current = current->next;
}
```

This demonstrates one of the fundamental concepts of C: **using pointers to navigate dynamically allocated memory**.

---

# 🧠 Memory Arena Allocator

Instead of allocating every node individually with `malloc`, this project uses a **memory arena allocator**.

An arena is a large block of memory allocated upfront.

Conceptually:

```text
Arena
+------------------------------------------------+
|                                                |
|      available memory for multiple nodes       |
|                                                |
+------------------------------------------------+
```

The arena then provides smaller portions of this memory whenever a new node is required.

For example:

```text
Arena
+------------------------------------------------+
| Node 1 | Node 2 | Node 3 | Node 4 | free ...  |
+------------------------------------------------+
```

The main idea is that the arena owns the memory.

Instead of doing:

```c
malloc(sizeof(Node));
malloc(sizeof(Node));
malloc(sizeof(Node));
```

the program can allocate a larger block once and then obtain portions of that block for individual nodes.

## Why Use an Arena?

Arena allocation can provide several advantages:

* Fewer calls to `malloc`.
* Simple and fast allocation.
* Better control over memory ownership.
* Easy cleanup of many allocations at once.
* Useful for understanding how custom memory allocators work.

One important characteristic is that individual objects generally aren't freed independently. Instead, the arena itself can be released when the objects are no longer needed.

For example:

```c
free(arena->memory);
free(arena);
```

This can make memory management considerably simpler for certain workloads.

---

# 🔗 Relationship Between the Arena and Linked List

The two main concepts in this project are independent but work together.

The **linked list** determines how the nodes are connected:

```text
Node A
  |
  v
Node B
  |
  v
Node C
  |
  v
NULL
```

The **arena allocator** determines where the memory for those nodes comes from.

```text
                Arena
                  |
        +---------+---------+
        |         |         |
        v         v         v
      Node A    Node B    Node C
        |         |         |
        +-------->+------->+
                            |
                           NULL
```

Each node still contains a pointer to the next node. The arena simply provides the memory used to store those nodes.

---

# ⚙️ Main Concepts Demonstrated

This project focuses on several important C concepts:

### Pointers

Pointers store memory addresses and allow nodes to reference other nodes.

### Structures

`struct` is used to define the layout of each linked-list node.

```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```

### Dynamic Memory

Memory is managed manually rather than automatically.

### Memory Arenas

A custom allocator manages a larger block of memory from which individual nodes can be obtained.

### Linked Lists

Nodes are dynamically connected through pointers rather than being stored sequentially like an array.

### Manual Memory Management

The programmer is responsible for understanding ownership and ensuring allocated memory is eventually released appropriately.

---

# 🚀 Goals of the Project

The main goal of this repository is educational: to better understand how data structures and memory management work at a lower level.

The project provides practical experience with:

* `malloc`
* `free`
* Pointers
* Structures
* Pointer dereferencing
* Dynamic memory
* Custom allocation strategies
* Linked-list traversal
* Memory ownership

---

# 📂 Project Structure

A possible project structure is:

```text
linked-list-arena/
│
├── src/
│   ├── linked_list.c
│   ├── linked_list.h
│   ├── arena.c
│   └── arena.h
│
├── main.c
├── Makefile
└── README.md
```

The exact structure may evolve as the project develops.

---

# 🛠️ Compilation

Using GCC:

```bash
gcc -Wall -Wextra -Wpedantic -std=c11 main.c src/*.c -o linked_list
```

Then run:

```bash
./linked_list
```

---

# 📚 Future Updates

This project is still a work in progress.

**Future updates may come with time**, including improvements to the arena allocator, additional linked-list operations, better error handling, testing, performance improvements, and potentially other data structures using the same memory-management approach.

The goal is to continue expanding the project while exploring deeper concepts of the C language and low-level memory management.

---

## 📜 License

This project is intended primarily for educational and learning purposes.
