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

implement **a real-world project using Linked Lists**, such as a **to-do list or music playlist manager** 🚀