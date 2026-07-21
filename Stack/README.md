# Stack

## 📖 What is Stack?

A **Stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle.

The last element added is the first element removed.

---

## 📌 LIFO
Example:

```
      Top
       │
   +-------+
   |  30   |
   +-------+
   |  20   |
   +-------+
   |  10   |
   +-------+

push ↑

pop  ↓
```

Think of a stack of plates.
You always put a new plate on the top, and you always take the top plate first.


---

## 🛠 Operations

| Operation | Description | Time Complexity |
|-----------|-------------|-----------------|
| push()    | Add an element to the top        | O(1) |
| pop()     | Remove the top element           | O(1) |
| top()     | Return the top element           | O(1) |
| isEmpty() | Check whether the stack is empty | O(1) |

---

## 📂 Array Implementation

## 📂 Array Implementation

```cpp
int* data;
int capacity;
int used;
```

| Variable | Description |
|----------|-------------|
| data     | Dynamic array storing stack elements |
| capacity | Maximum number of elements |
| used     | Current number of elements |
