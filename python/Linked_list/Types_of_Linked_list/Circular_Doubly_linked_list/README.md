# **Circular Doubly Linked List in JavaScript (CDLL)**
A **Circular Doubly Linked List (CDLL)** is a type of **linked list** where:
1. Each node has **two pointers**: 
   - `next` (points to the next node)
   - `prev` (points to the previous node)
2. The **last node** connects back to the **first node**, forming a **circular structure**.

## **📌 Why Use Circular Doubly Linked List?**
- Efficient **forward & backward traversal**.
- No need to handle `null` at the start or end.
- Used in **circular buffers, multiplayer game logic, and scheduling**.

---

## **1️⃣ Node Structure**
Each **node** contains:
- `data` → Stores the value.
- `next` → Points to the next node.
- `prev` → Points to the previous node.

### **🔹 Code:**
```js
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
    this.prev = null;
  }
}
```

---

## **2️⃣ Circular Doubly Linked List Class**
- **Properties**:
  - `head` → First node in the list.
  - `tail` → Last node in the list.

### **🔹 Code:**
```js
class CircularDoublyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
  }
}
```

---

## **3️⃣ Operations on Circular Doubly Linked List**
### **🔹 1. Insert at the Beginning**
**Steps:**
1. Create a new node.
2. If **list is empty**, set `head` and `tail` to the new node (`tail.next = head` and `head.prev = tail`).
3. Otherwise:
   - Set new node's `next` to `head`.
   - Set `head.prev` to new node.
   - Update `tail.next` to new node.
   - Update `head` to new node.

### **🔹 Code:**
```js
  insertAtBeginning(data) {
    let newNode = new Node(data);

    if (!this.head) {
      this.head = this.tail = newNode;
      this.head.next = this.head;
      this.head.prev = this.head;
    } else {
      newNode.next = this.head;
      newNode.prev = this.tail;
      this.head.prev = newNode;
      this.tail.next = newNode;
      this.head = newNode;
    }
  }
```
✅ **Time Complexity:** `O(1)`

---

### **🔹 2. Insert at the End**
**Steps:**
1. Create a new node.
2. If **list is empty**, set `head` and `tail` to the new node.
3. Otherwise:
   - Set `tail.next` to new node.
   - Set `newNode.prev` to `tail`.
   - Set `newNode.next` to `head`.
   - Update `head.prev` to new node.
   - Update `tail` to new node.

### **🔹 Code:**
```js
  insertAtEnd(data) {
    let newNode = new Node(data);

    if (!this.head) {
      this.head = this.tail = newNode;
      this.head.next = this.head;
      this.head.prev = this.head;
    } else {
      newNode.prev = this.tail;
      newNode.next = this.head;
      this.tail.next = newNode;
      this.head.prev = newNode;
      this.tail = newNode;
    }
  }
```
✅ **Time Complexity:** `O(1)`

---

### **🔹 3. Delete a Node by Value**
**Steps:**
1. **If the list is empty**, return.
2. **If deleting head**, update `head` and `tail.next`.
3. **If deleting tail**, update `tail` and `head.prev`.
4. **Otherwise**, update `prev.next` and `next.prev`.

### **🔹 Code:**
```js
  deleteNode(value) {
    if (!this.head) return;

    let current = this.head;

    // Traverse to find the node
    do {
      if (current.data === value) {
        if (current === this.head) {
          this.head = this.head.next;
          this.tail.next = this.head;
          this.head.prev = this.tail;
        } else if (current === this.tail) {
          this.tail = this.tail.prev;
          this.tail.next = this.head;
          this.head.prev = this.tail;
        } else {
          current.prev.next = current.next;
          current.next.prev = current.prev;
        }
        return;
      }
      current = current.next;
    } while (current !== this.head);
  }
```
✅ **Time Complexity:** `O(n)`

---

### **🔹 4. Search for a Node**
Traverse **circularly** and check if `data === value`.

### **🔹 Code:**
```js
  search(value) {
    if (!this.head) return false;

    let current = this.head;
    do {
      if (current.data === value) return true;
      current = current.next;
    } while (current !== this.head);

    return false;
  }
```
✅ **Time Complexity:** `O(n)`

---

### **🔹 5. Print the Circular Doubly Linked List**
We **traverse** forward from `head` and print elements.

### **🔹 Code:**
```js
  printList() {
    if (!this.head) {
      console.log("List is empty");
      return;
    }

    let current = this.head;
    let result = "";
    
    do {
      result += current.data + " ⇄ ";
      current = current.next;
    } while (current !== this.head);

    console.log(result + "(HEAD)");
  }
```
✅ **Time Complexity:** `O(n)`

---

## **4️⃣ Complete Circular Doubly Linked List Code**
```js
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
    this.prev = null;
  }
}

class CircularDoublyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  insertAtBeginning(data) {
    let newNode = new Node(data);
    if (!this.head) {
      this.head = this.tail = newNode;
      this.head.next = this.head;
      this.head.prev = this.head;
    } else {
      newNode.next = this.head;
      newNode.prev = this.tail;
      this.head.prev = newNode;
      this.tail.next = newNode;
      this.head = newNode;
    }
  }

  insertAtEnd(data) {
    let newNode = new Node(data);
    if (!this.head) {
      this.head = this.tail = newNode;
      this.head.next = this.head;
      this.head.prev = this.head;
    } else {
      newNode.prev = this.tail;
      newNode.next = this.head;
      this.tail.next = newNode;
      this.head.prev = newNode;
      this.tail = newNode;
    }
  }

  deleteNode(value) {
    if (!this.head) return;

    let current = this.head;
    do {
      if (current.data === value) {
        if (current === this.head) {
          this.head = this.head.next;
          this.tail.next = this.head;
          this.head.prev = this.tail;
        } else if (current === this.tail) {
          this.tail = this.tail.prev;
          this.tail.next = this.head;
          this.head.prev = this.tail;
        } else {
          current.prev.next = current.next;
          current.next.prev = current.prev;
        }
        return;
      }
      current = current.next;
    } while (current !== this.head);
  }

  printList() {
    if (!this.head) {
      console.log("List is empty");
      return;
    }

    let current = this.head;
    let result = "";
    do {
      result += current.data + " ⇄ ";
      current = current.next;
    } while (current !== this.head);

    console.log(result + "(HEAD)");
  }
}

// Example Usage
let cdll = new CircularDoublyLinkedList();
cdll.insertAtEnd(10);
cdll.insertAtEnd(20);
cdll.insertAtBeginning(5);
cdll.printList();
```

---

## **🔥 Summary**
- **CDLL allows efficient forward & backward traversal**.
- **Used in scheduling, gaming, and memory management**.
- **Operations:**
  - `O(1)`: Insert at beginning/end.
  - `O(n)`: Search & Delete.

