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

---

# <center>🐍Python
 


## **Circular Doubly Linked List (CDLL) in Python**
A **Circular Doubly Linked List (CDLL)** is a linked list where:
- **Each node has two pointers**:
  - `next` → Points to the next node.
  - `prev` → Points to the previous node.
- The **last node links back to the first node** forming a circular structure.

---

## **1️⃣ Node Class**
Each **Node** contains:
- `data` → Stores the value.
- `next` → Points to the next node.
- `prev` → Points to the previous node.

### **🔹 Code:**
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
```

---

## **2️⃣ Circular Doubly Linked List Class**
- **Properties**:
  - `head` → First node in the list.
  - `tail` → Last node in the list.

### **🔹 Code:**
```python
class CircularDoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
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
```python
    def insert_at_beginning(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = self.tail = new_node
            self.head.next = self.head
            self.head.prev = self.head
        else:
            new_node.next = self.head
            new_node.prev = self.tail
            self.head.prev = new_node
            self.tail.next = new_node
            self.head = new_node
```
✅ **Time Complexity:** `O(1)`

---

### **🔹 2. Insert at the End**
**Steps:**
1. Create a new node.
2. If **list is empty**, set `head` and `tail` to the new node.
3. Otherwise:
   - Set `tail.next` to new node.
   - Set `new_node.prev` to `tail`.
   - Set `new_node.next` to `head`.
   - Update `head.prev` to new node.
   - Update `tail` to new node.

### **🔹 Code:**
```python
    def insert_at_end(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = self.tail = new_node
            self.head.next = self.head
            self.head.prev = self.head
        else:
            new_node.prev = self.tail
            new_node.next = self.head
            self.tail.next = new_node
            self.head.prev = new_node
            self.tail = new_node
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
```python
    def delete_node(self, value):
        if self.head is None:
            return

        current = self.head

        while True:
            if current.data == value:
                if current == self.head:
                    self.head = self.head.next
                    self.tail.next = self.head
                    self.head.prev = self.tail
                elif current == self.tail:
                    self.tail = self.tail.prev
                    self.tail.next = self.head
                    self.head.prev = self.tail
                else:
                    current.prev.next = current.next
                    current.next.prev = current.prev
                return
            
            current = current.next
            if current == self.head:
                break
```
✅ **Time Complexity:** `O(n)`

---

### **🔹 4. Search for a Node**
Traverse **circularly** and check if `data == value`.

### **🔹 Code:**
```python
    def search(self, value):
        if self.head is None:
            return False

        current = self.head
        while True:
            if current.data == value:
                return True
            current = current.next
            if current == self.head:
                break

        return False
```
✅ **Time Complexity:** `O(n)`

---

### **🔹 5. Print the Circular Doubly Linked List**
We **traverse** forward from `head` and print elements.

### **🔹 Code:**
```python
    def print_list(self):
        if self.head is None:
            print("List is empty")
            return

        current = self.head
        result = ""
        while True:
            result += str(current.data) + " ⇄ "
            current = current.next
            if current == self.head:
                break

        print(result + "(HEAD)")
```
✅ **Time Complexity:** `O(n)`

---

## **4️⃣ Complete Circular Doubly Linked List Code**
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class CircularDoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = self.tail = new_node
            self.head.next = self.head
            self.head.prev = self.head
        else:
            new_node.next = self.head
            new_node.prev = self.tail
            self.head.prev = new_node
            self.tail.next = new_node
            self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = self.tail = new_node
            self.head.next = self.head
            self.head.prev = self.head
        else:
            new_node.prev = self.tail
            new_node.next = self.head
            self.tail.next = new_node
            self.head.prev = new_node
            self.tail = new_node

    def delete_node(self, value):
        if self.head is None:
            return

        current = self.head
        while True:
            if current.data == value:
                if current == self.head:
                    self.head = self.head.next
                    self.tail.next = self.head
                    self.head.prev = self.tail
                elif current == self.tail:
                    self.tail = self.tail.prev
                    self.tail.next = self.head
                    self.head.prev = self.tail
                else:
                    current.prev.next = current.next
                    current.next.prev = current.prev
                return
            current = current.next
            if current == self.head:
                break

    def search(self, value):
        if self.head is None:
            return False

        current = self.head
        while True:
            if current.data == value:
                return True
            current = current.next
            if current == self.head:
                break

        return False

    def print_list(self):
        if self.head is None:
            print("List is empty")
            return

        current = self.head
        result = ""
        while True:
            result += str(current.data) + " ⇄ "
            current = current.next
            if current == self.head:
                break

        print(result + "(HEAD)")

# Example Usage
cdll = CircularDoublyLinkedList()
cdll.insert_at_end(10)
cdll.insert_at_end(20)
cdll.insert_at_beginning(5)
cdll.print_list()
```

---

## **🔥 Summary**
- **Circular Doubly Linked List allows efficient forward & backward traversal**.
- **Used in scheduling, gaming, and memory management**.
- **Operations:**
  - `O(1)`: Insert at beginning/end.
  - `O(n)`: Search & Delete.

---
<br>
<br>

Alright! Let’s break it down in a **structured, easy-to-understand, and detailed** way so that you can **fully grasp** Circular Doubly Linked Lists (CDLL) and confidently implement them in Python.

---

# **🔹 Circular Doubly Linked List (CDLL) - Explained in Detail**
## **📌 What is a Circular Doubly Linked List (CDLL)?**
A **Circular Doubly Linked List (CDLL)** is an **advanced** type of linked list where:
1. Each node **stores** data.
2. Each node has **two pointers**:
   - `next` → Points to the **next node**.
   - `prev` → Points to the **previous node**.
3. The **last node links back to the first node**, forming a **circular structure**.

---

## **📌 How CDLL Works?**
Think of a **CDLL as a train** 🚆 where:
- The **engine (first coach)** is **linked to the last coach**.
- Each **coach (node)** has a **link to the next** and **previous coach**.
- The **last coach (tail node)** is **linked back to the engine**.

---

## **🔹 Advantages of CDLL**
✔ **Efficient Bi-Directional Traversal** (Move forward & backward).  
✔ **Better Memory Usage** than doubly linked lists.  
✔ **Used in Scheduling, Circular Queues, and Memory Management.**  

---

# **🔹 Implementation of CDLL in Python**
### **📌 1️⃣ Define the Node Structure**
Every node consists of:
- **`data`** → Stores the value.
- **`next`** → Pointer to the next node.
- **`prev`** → Pointer to the previous node.

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None  # Points to next node
        self.prev = None  # Points to previous node
```
---

### **📌 2️⃣ Create the Circular Doubly Linked List Class**
This class manages:
- **Head & Tail Pointers**.
- **Insertion, Deletion, and Traversal Methods**.

```python
class CircularDoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None  # Keeps track of the last node
```

---

# **🔹 Operations on Circular Doubly Linked List**
## **1️⃣ Insert at the Beginning**
**Steps:**
1. Create a **new node**.
2. If **list is empty**, set `head` and `tail` to the new node.
3. Otherwise:
   - Update **new node’s `next` to point to `head`**.
   - Update **head’s `prev` to point to the new node**.
   - Set **new node’s `prev` to `tail`**.
   - Set **tail’s `next` to new node**.
   - Update `head`.

```python
    def insert_at_beginning(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = self.tail = new_node
            self.head.next = self.head
            self.head.prev = self.head
        else:
            new_node.next = self.head
            new_node.prev = self.tail
            self.head.prev = new_node
            self.tail.next = new_node
            self.head = new_node
```

✅ **Time Complexity:** `O(1)`

---

## **2️⃣ Insert at the End**
**Steps:**
1. Create a **new node**.
2. If **list is empty**, set `head` and `tail` to new node.
3. Otherwise:
   - Set **new node’s `prev` to `tail`**.
   - Set **new node’s `next` to `head`**.
   - Update **tail’s `next` to new node**.
   - Update **head’s `prev` to new node**.
   - Set **tail to new node**.

```python
    def insert_at_end(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = self.tail = new_node
            self.head.next = self.head
            self.head.prev = self.head
        else:
            new_node.prev = self.tail
            new_node.next = self.head
            self.tail.next = new_node
            self.head.prev = new_node
            self.tail = new_node
```

✅ **Time Complexity:** `O(1)`

---

## **3️⃣ Delete a Node**
**Steps:**
1. **If the list is empty, return.**
2. **If deleting the head:**
   - Move `head` forward.
   - Update `tail.next` and `head.prev`.
3. **If deleting the tail:**
   - Move `tail` backward.
   - Update `tail.next` and `head.prev`.
4. **If deleting a middle node:**
   - Adjust **previous node’s `next`** and **next node’s `prev`**.

```python
    def delete_node(self, value):
        if self.head is None:
            return

        current = self.head
        while True:
            if current.data == value:
                if current == self.head:
                    self.head = self.head.next
                    self.tail.next = self.head
                    self.head.prev = self.tail
                elif current == self.tail:
                    self.tail = self.tail.prev
                    self.tail.next = self.head
                    self.head.prev = self.tail
                else:
                    current.prev.next = current.next
                    current.next.prev = current.prev
                return
            current = current.next
            if current == self.head:
                break
```

✅ **Time Complexity:** `O(n)`

---

## **4️⃣ Search for a Node**
- **Traverse** the list and check if `data == value`.

```python
    def search(self, value):
        if self.head is None:
            return False

        current = self.head
        while True:
            if current.data == value:
                return True
            current = current.next
            if current == self.head:
                break

        return False
```

✅ **Time Complexity:** `O(n)`

---

## **5️⃣ Print the Circular Doubly Linked List**
**Steps:**
1. **If the list is empty, print `List is empty`.**
2. **Else, traverse forward from `head` and print elements.**

```python
    def print_list(self):
        if self.head is None:
            print("List is empty")
            return

        current = self.head
        result = ""
        while True:
            result += str(current.data) + " ⇄ "
            current = current.next
            if current == self.head:
                break

        print(result + "(HEAD)")
```

✅ **Time Complexity:** `O(n)`

---

# **🔹 Full Working Code**
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class CircularDoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = self.tail = new_node
            self.head.next = self.head
            self.head.prev = self.head
        else:
            new_node.next = self.head
            new_node.prev = self.tail
            self.head.prev = new_node
            self.tail.next = new_node
            self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = self.tail = new_node
            self.head.next = self.head
            self.head.prev = self.head
        else:
            new_node.prev = self.tail
            new_node.next = self.head
            self.tail.next = new_node
            self.head.prev = new_node
            self.tail = new_node

    def print_list(self):
        if self.head is None:
            print("List is empty")
            return

        current = self.head
        result = ""
        while True:
            result += str(current.data) + " ⇄ "
            current = current.next
            if current == self.head:
                break

        print(result + "(HEAD)")

# Example Usage
cdll = CircularDoublyLinkedList()
cdll.insert_at_end(10)
cdll.insert_at_end(20)
cdll.insert_at_beginning(5)
cdll.print_list()
```

---

