# Queue

## 📖 What is Queue?

A **Queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle.

The first element added is the first element removed.

---

## 📌 FIFO

Example:

```
Front                     Rear
  ↓                         ↓

+-------+-------+-------+
|  10   |  20   |  30   |
+-------+-------+-------+

dequeue()            enqueue()
```

Think of a line of people waiting for a bus.

The first person to join the line is the first person to leave the line.

---

## 🛠 Operations

| Operation | Description | Time Complexity |
|-----------|-------------|-----------------|
| enqueue() | Add an element to the rear | O(1) |
| dequeue() | Remove the front element | O(1) |
| front() | Return the front element | O(1) |
| isEmpty() | Check whether the queue is empty | O(1) |

---

## 📂 Array Implementation

```cpp
int* data;
int capacity;
int used;
int front;
int rear;
```

| Variable | Description |
|----------|-------------|
| data | Dynamic array storing queue elements |
| capacity | Maximum number of elements |
| used | Current number of elements |
| front | Index of the first element |
| rear | Index where the next element is inserted |
