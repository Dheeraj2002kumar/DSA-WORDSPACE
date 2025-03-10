# **📌 Everything About Types of Linked List in JavaScript**  

A **Linked List** is a linear data structure where elements (nodes) are linked using pointers. Unlike arrays, linked lists are dynamic and allow efficient insertions and deletions.

---

## **🔹 Why Use Linked Lists Instead of Arrays?**
| Feature | Arrays | Linked Lists |
|---------|--------|-------------|
| **Memory** | Fixed size (static) | Dynamic size (flexible) |
| **Insertion** | Expensive (O(n)) | Efficient (O(1) at head/tail) |
| **Deletion** | Expensive (O(n)) | Efficient (O(1) at head/tail) |
| **Random Access** | O(1) | O(n) |
| **Search** | O(n) | O(n) |

---

## **📌 Types of Linked Lists in JavaScript**
### 1️⃣ **Singly Linked List**
### 2️⃣ **Doubly Linked List**
### 3️⃣ **Circular Linked List**
### 4️⃣ **Doubly Circular Linked List**

---

# **1️⃣ Singly Linked List (SLL)**
A **Singly Linked List** consists of nodes where each node contains:
1. **Data**
2. **Pointer (next) to the next node**  

### **➡️ Example:**
```
[10] → [20] → [30] → null
```
👉 The last node points to `null`.

### **🔹 Implementation of Singly Linked List**
```javascript
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class SinglyLinkedList {
  constructor() {
    this.head = null;
  }

  // Insert at the end
  append(data) {
    let newNode = new Node(data);
    if (!this.head) {
      this.head = newNode;
      return;
    }
    let current = this.head;
    while (current.next) {
      current = current.next;
    }
    current.next = newNode;
  }

  // Insert at the beginning
  prepend(data) {
    let newNode = new Node(data);
    newNode.next = this.head;
    this.head = newNode;
  }

  // Delete a node by value
  delete(data) {
    if (!this.head) return;
    if (this.head.data === data) {
      this.head = this.head.next;
      return;
    }
    let current = this.head;
    while (current.next && current.next.data !== data) {
      current = current.next;
    }
    if (current.next) current.next = current.next.next;
  }

  // Print the list
  printList() {
    let current = this.head;
    let result = "";
    while (current) {
      result += `${current.data} → `;
      current = current.next;
    }
    console.log(result + "null");
  }
}

// Example usage:
let list = new SinglyLinkedList();
list.append(10);
list.append(20);
list.prepend(5);
list.printList(); // Output: 5 → 10 → 20 → null
list.delete(10);
list.printList(); // Output: 5 → 20 → null
```
✅ **Operations Complexity:**
- Insert at head: `O(1)`
- Insert at tail: `O(n)`
- Delete a node: `O(n)`
- Search: `O(n)`

---

# **2️⃣ Doubly Linked List (DLL)**
Each node has:
1. **Data**
2. **Pointer to next node (`next`)**
3. **Pointer to previous node (`prev`)**

### **➡️ Example:**
```
null ← [10] ⇄ [20] ⇄ [30] → null
```
👉 Each node has **both forward and backward links**.

### **🔹 Implementation of Doubly Linked List**
```javascript
class DNode {
  constructor(data) {
    this.data = data;
    this.next = null;
    this.prev = null;
  }
}

class DoublyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  // Insert at the end
  append(data) {
    let newNode = new DNode(data);
    if (!this.head) {
      this.head = this.tail = newNode;
      return;
    }
    this.tail.next = newNode;
    newNode.prev = this.tail;
    this.tail = newNode;
  }

  // Insert at the beginning
  prepend(data) {
    let newNode = new DNode(data);
    if (!this.head) {
      this.head = this.tail = newNode;
      return;
    }
    newNode.next = this.head;
    this.head.prev = newNode;
    this.head = newNode;
  }

  // Delete a node by value
  delete(data) {
    if (!this.head) return;
    let current = this.head;
    while (current && current.data !== data) {
      current = current.next;
    }
    if (!current) return;
    if (current === this.head) this.head = current.next;
    if (current === this.tail) this.tail = current.prev;
    if (current.prev) current.prev.next = current.next;
    if (current.next) current.next.prev = current.prev;
  }

  // Print the list
  printList() {
    let current = this.head;
    let result = "";
    while (current) {
      result += `${current.data} ⇄ `;
      current = current.next;
    }
    console.log(result + "null");
  }
}

// Example usage:
let dList = new DoublyLinkedList();
dList.append(10);
dList.append(20);
dList.prepend(5);
dList.printList(); // Output: 5 ⇄ 10 ⇄ 20 ⇄ null
dList.delete(10);
dList.printList(); // Output: 5 ⇄ 20 ⇄ null
```
✅ **Operations Complexity:**
- Insert at head: `O(1)`
- Insert at tail: `O(1)`
- Delete a node: `O(n)`
- Search: `O(n)`

---

# **3️⃣ Circular Linked List (CLL)**
The **last node points back to the first node**, making a loop.

### **➡️ Example:**
```
[10] → [20] → [30] → [10] (back to start)
```
### **🔹 Implementation of Circular Linked List**
```javascript
class CNode {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class CircularLinkedList {
  constructor() {
    this.head = null;
  }

  // Insert at the end
  append(data) {
    let newNode = new CNode(data);
    if (!this.head) {
      this.head = newNode;
      this.head.next = this.head; // Circular link
      return;
    }
    let current = this.head;
    while (current.next !== this.head) {
      current = current.next;
    }
    current.next = newNode;
    newNode.next = this.head;
  }

  // Print the list
  printList() {
    if (!this.head) return;
    let current = this.head;
    let result = "";
    do {
      result += `${current.data} → `;
      current = current.next;
    } while (current !== this.head);
    console.log(result + "(back to start)");
  }
}

// Example usage:
let cList = new CircularLinkedList();
cList.append(10);
cList.append(20);
cList.append(30);
cList.printList(); // Output: 10 → 20 → 30 → (back to start)
```
✅ **Operations Complexity:**
- Insert at head: `O(1)`
- Insert at tail: `O(n)`
- Delete a node: `O(n)`
- Search: `O(n)`

---

# **📌 Conclusion**
| **Type** | **Use Case** |
|----------|-------------|
| **Singly Linked List** | Basic operations where backward traversal is not needed |
| **Doubly Linked List** | Fast traversal in both directions |
| **Circular Linked List** | Ideal for circular scheduling, playlists, etc. |

---

<br>
<br>

# <center>🐍Python

<br>

# **📌 Types of Linked Lists in Python**  

### **1️⃣ Singly Linked List (SLL)**
### **2️⃣ Doubly Linked List (DLL)**
### **3️⃣ Circular Linked List (CLL)**

---

## **1️⃣ Singly Linked List (SLL)**
A **Singly Linked List** consists of nodes where each node contains:
1. **Data**
2. **Pointer (next) to the next node**  

### **➡️ Example:**
```
[10] → [20] → [30] → None
```
👉 The last node points to `None`.

### **🔹 Implementation of Singly Linked List**
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    # Insert at the end
    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    # Insert at the beginning
    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # Delete a node by value
    def delete(self, data):
        if not self.head:
            return
        if self.head.data == data:
            self.head = self.head.next
            return
        current = self.head
        while current.next and current.next.data != data:
            current = current.next
        if current.next:
            current.next = current.next.next

    # Print the list
    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" → ")
            current = current.next
        print("None")

# Example usage:
sll = SinglyLinkedList()
sll.append(10)
sll.append(20)
sll.prepend(5)
sll.print_list()  # Output: 5 → 10 → 20 → None
sll.delete(10)
sll.print_list()  # Output: 5 → 20 → None
```
✅ **Operations Complexity:**
- Insert at head: `O(1)`
- Insert at tail: `O(n)`
- Delete a node: `O(n)`
- Search: `O(n)`

---

## **2️⃣ Doubly Linked List (DLL)**
Each node has:
1. **Data**
2. **Pointer to next node (`next`)**
3. **Pointer to previous node (`prev`)**

### **➡️ Example:**
```
None ← [10] ⇄ [20] ⇄ [30] → None
```
👉 Each node has **both forward and backward links**.

### **🔹 Implementation of Doubly Linked List**
```python
class DNode:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # Insert at the end
    def append(self, data):
        new_node = DNode(data)
        if not self.head:
            self.head = self.tail = new_node
            return
        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node

    # Insert at the beginning
    def prepend(self, data):
        new_node = DNode(data)
        if not self.head:
            self.head = self.tail = new_node
            return
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    # Delete a node by value
    def delete(self, data):
        if not self.head:
            return
        current = self.head
        while current and current.data != data:
            current = current.next
        if not current:
            return
        if current == self.head:
            self.head = current.next
        if current == self.tail:
            self.tail = current.prev
        if current.prev:
            current.prev.next = current.next
        if current.next:
            current.next.prev = current.prev

    # Print the list
    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" ⇄ ")
            current = current.next
        print("None")

# Example usage:
dll = DoublyLinkedList()
dll.append(10)
dll.append(20)
dll.prepend(5)
dll.print_list()  # Output: 5 ⇄ 10 ⇄ 20 ⇄ None
dll.delete(10)
dll.print_list()  # Output: 5 ⇄ 20 ⇄ None
```
✅ **Operations Complexity:**
- Insert at head: `O(1)`
- Insert at tail: `O(1)`
- Delete a node: `O(n)`
- Search: `O(n)`

---

## **3️⃣ Circular Linked List (CLL)**
The **last node points back to the first node**, making a loop.

### **➡️ Example:**
```
[10] → [20] → [30] → [10] (back to start)
```
### **🔹 Implementation of Circular Linked List**
```python
class CNode:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    # Insert at the end
    def append(self, data):
        new_node = CNode(data)
        if not self.head:
            self.head = new_node
            self.head.next = self.head  # Circular link
            return
        current = self.head
        while current.next != self.head:
            current = current.next
        current.next = new_node
        new_node.next = self.head

    # Print the list
    def print_list(self):
        if not self.head:
            return
        current = self.head
        result = []
        while True:
            result.append(str(current.data))
            current = current.next
            if current == self.head:
                break
        print(" → ".join(result) + " → (back to start)")

# Example usage:
cll = CircularLinkedList()
cll.append(10)
cll.append(20)
cll.append(30)
cll.print_list()  # Output: 10 → 20 → 30 → (back to start)
```
✅ **Operations Complexity:**
- Insert at head: `O(1)`
- Insert at tail: `O(n)`
- Delete a node: `O(n)`
- Search: `O(n)`

---

# **📌 Conclusion**
| **Type** | **Use Case** |
|----------|-------------|
| **Singly Linked List** | Basic operations where backward traversal is not needed |
| **Doubly Linked List** | Fast traversal in both directions |
| **Circular Linked List** | Ideal for circular scheduling, playlists, etc. |

implement **a real-world project using Linked Lists**, such as a **to-do list or music playlist manager** 🚀