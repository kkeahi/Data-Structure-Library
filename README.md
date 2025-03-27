# Data Structures Library in C++


## Overview
This project is a C++ Data Structures Library that implements a variety of common data structures.
The library is designed to be modular, with each data structure having its own header (`.h`) and source (`.cpp`) file.

---

## Build and Compile Instructions

### Option 1: Use Precompiled Library
1. Download the `libdatastructures.a` file.
2. Compile and run your program using:
```bash
g++ -o main main.cpp -I include libdatastructures.a
./main
```

### Option 2: Clone and Rebuild
1. Clone the entire project:
```bash
git clone https://github.com/your-username/data-structures-lib.git
cd data-structures-lib
```
2. To rebuild and recompile:
```bash
# Compile all .cpp files to .o
g++ -c src/*.cpp -I include

# Create a static library
ar rcs libdatastructures.a *.o

# Compile and run main
g++ -o main main.cpp -I include libdatastructures.a
./main
```

---

## Supported Data Structures

### 1. Stack
- `Stack()`
- `~Stack()`
- `bool is_empty() const`
- `int peek() const`
- `void push(int value)`
- `bool pop()`

### 2. Queue
- `Queue()`
- `~Queue()`
- `bool is_empty() const`
- `int get_size() const`
- `int front() const`
- `int rear() const`
- `void enqueue(int value)`
- `int dequeue()`

### 3. Deque
- `Deque()`
- `~Deque()`
- `void print() const`
- `bool is_empty() const`
- `int get_size() const`
- `int front() const`
- `int rear() const`
- `void push_front(int value)`
- `void push_rear(int value)`
- `int pop_front()`
- `int pop_rear()`

### 4. Binary Search Tree
- `BinarySearchTree()`
- `~BinarySearchTree()`
- `void insert(int value)`
- `void remove(int value)`
- `Node* search(int value) const`
- `Node* get_root() const`
- `Node* findMin() const`
- `Node* findMax() const`
- `int height() const`
- `void inorderTraversal(Node* node) const`
- `void preorderTraversal(Node* node) const`
- `void postorderTraversal(Node* node) const`

### 5. Singly Linked List
- `SinglyLinkedList()`
- `~SinglyLinkedList()`
- `void print_list() const`
- `int get_size() const`
- `int find(int value) const`
- `void insert_at_tail(int value)`
- `void insert_at_head(int value)`
- `bool insert_at_index(int value, int index)`
- `bool delete_tail()`
- `bool delete_head()`
- `bool delete_at_index(int index)`

### 6. Doubly Linked List
- `DoublyLinkedList()`
- `~DoublyLinkedList()`
- `void print_list() const`
- `int get_size() const`
- `int find(int value) const`
- `void insert_at_tail(int value)`
- `void insert_at_head(int value)`
- `bool insert_at_index(int value, int index)`
- `bool delete_tail()`
- `bool delete_head()`
- `bool delete_at_index(int index)`

### 7. Circular Linked List
- `CircularLinkedList()`
- `~CircularLinkedList()`
- `void print_list() const`
- `int get_size() const`
- `int find(int value) const`
- `void insert_at_tail(int value)`
- `void insert_at_head(int value)`
- `bool insert_at_index(int value, int index)`
- `bool delete_tail()`
- `bool delete_head()`
- `bool delete_at_index(int index)`

### 8. Circular Doubly Linked List
- `CircularDoublyLinkedList()`
- `~CircularDoublyLinkedList()`
- `void print_list() const`
- `int get_size() const`
- `int find(int value) const`
- `void insert_at_tail(int value)`
- `void insert_at_head(int value)`
- `bool insert_at_index(int value, int index)`
- `bool delete_tail()`
- `bool delete_head()`
- `bool delete_at_index(int index)`