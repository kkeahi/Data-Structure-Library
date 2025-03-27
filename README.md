# Data Structures Library in C++


## Overview
This project is a C++ Data Structure Library that implements a variety of common data structures.
The library is designed to be modular, with each data structure having its own header (`.h`) and source (`.cpp`) file.

---

## Build and Compile Instructions


1. Clone the entire project:
```bash
git clone https://github.com/trenston/data-structures-lib.git
```
2. To build and compile:
```bash
# Create a build directory inside the cloned project
mkdir -p data-structures-lib/build

# Compile all .cpp files into .o files in build/
for file in data-structures-lib/src/*.cpp; do
    g++ -c $file -I data-structures-lib/include -o data-structures-lib/build/$(basename ${file%.cpp}.o)
done

# Create a static library in the root directory
ar rcs libdatastructures.a data-structures-lib/build/*.o

# Compile main.cpp and link the static library
g++ -o main main.cpp -I data-structures-lib/include libdatastructures.a

# Run the main executable
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