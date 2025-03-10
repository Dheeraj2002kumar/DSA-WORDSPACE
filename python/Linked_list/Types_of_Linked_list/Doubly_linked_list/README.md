# **📌 Doubly Linked List (DLL) in JavaScript - Complete Guide**

A **Doubly Linked List (DLL)** is an advanced version of a **Singly Linked List (SLL)** that allows **bidirectional traversal** of nodes. It is an important **Data Structure and Algorithm (DSA) topic** frequently asked in **technical interviews**. 🚀

---

# **1️⃣ What is a Doubly Linked List?**
A **Doubly Linked List** consists of **nodes**, where each node contains:
- **Data** (value stored in the node)
- **Pointer to the next node**
- **Pointer to the previous node**

📌 Unlike **Singly Linked List**, which can only be traversed forward, **Doubly Linked List** supports **both forward and backward traversal**.

---

# **2️⃣ Why Use a Doubly Linked List?**
✅ **Advantages:**
- **Bidirectional Traversal** (both forward & backward)
- **Efficient Deletion & Insertion** (no need to traverse like in SLL)
- **More Flexible than SLL**  

❌ **Disadvantages:**
- **More Memory Usage** (due to extra `prev` pointer)
- **Extra Complexity** (additional pointer updates)

---

# **3️⃣ Implementation of Doubly Linked List in JavaScript**
We will implement a **Doubly Linked List Class** with various operations.

---

## **🔹 Creating a Node Class**
Each node contains **data**, **next pointer**, and **prev pointer**.

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

## **🔹 Creating a Doubly Linked List Class**
```js
class DoublyLinkedList {
    constructor() {
        this.head = null;  // Head points to the first node
        this.tail = null;  // Tail points to the last node
    }
}
```

---

# **4️⃣ Operations on Doubly Linked List**
## **🔹 1. Insert at the Beginning**
New node → **becomes the new head**.

### **➡️ Example:**
```
Before: NULL ← [10] → NULL
Insert(5)
After:  NULL ← [5] ⇄ [10] → NULL
```
### **🔹 Code:**
```js
insertAtBeginning(data) {
    let newNode = new Node(data);
    if (!this.head) {
        this.head = this.tail = newNode;
        return;
    }
    newNode.next = this.head;
    this.head.prev = newNode;
    this.head = newNode;
}
```
✅ **Time Complexity:** `O(1)`

---

## **🔹 2. Insert at the End**
New node → **becomes the new tail**.

### **➡️ Example:**
```
Before: NULL ← [10] → NULL
Insert(20)
After:  NULL ← [10] ⇄ [20] → NULL
```
### **🔹 Code:**
```js
insertAtEnd(data) {
    let newNode = new Node(data);
    if (!this.head) {
        this.head = this.tail = newNode;
        return;
    }
    this.tail.next = newNode;
    newNode.prev = this.tail;
    this.tail = newNode;
}
```
✅ **Time Complexity:** `O(1)`

---

## **🔹 3. Insert at a Specific Position**
1. Traverse to the desired position.
2. Insert the new node.

### **🔹 Code:**
```js
insertAtPosition(data, position) {
    if (position === 0) {
        this.insertAtBeginning(data);
        return;
    }

    let newNode = new Node(data);
    let current = this.head;
    let index = 0;

    while (current && index < position - 1) {
        current = current.next;
        index++;
    }

    if (!current) {
        this.insertAtEnd(data);
        return;
    }

    newNode.next = current.next;
    newNode.prev = current;

    if (current.next) {
        current.next.prev = newNode;
    }

    current.next = newNode;

    if (!newNode.next) {
        this.tail = newNode;
    }
}
```
✅ **Time Complexity:** `O(n)`

---

## **🔹 4. Delete a Node by Value**
1. Find the node with the given value.
2. Remove it from the linked list.

### **➡️ Example:**
```
Before: NULL ← [10] ⇄ [20] ⇄ [30] → NULL
Delete(20)
After:  NULL ← [10] ⇄ [30] → NULL
```
### **🔹 Code:**
```js
deleteNode(value) {
    if (!this.head) return;

    if (this.head.data === value) {
        this.head = this.head.next;
        if (this.head) this.head.prev = null;
        return;
    }

    let current = this.head;

    while (current && current.data !== value) {
        current = current.next;
    }

    if (!current) return;

    if (current.next) {
        current.next.prev = current.prev;
    }

    if (current.prev) {
        current.prev.next = current.next;
    }

    if (!current.next) {
        this.tail = current.prev;
    }
}
```
✅ **Time Complexity:** `O(n)`

---

## **🔹 5. Search for a Node**
Check if a given value exists in the list.

### **🔹 Code:**
```js
search(value) {
    let current = this.head;
    while (current) {
        if (current.data === value) return true;
        current = current.next;
    }
    return false;
}
```
✅ **Time Complexity:** `O(n)`

---

## **🔹 6. Print the Doubly Linked List**
### **🔹 Code:**
```js
printList() {
    let current = this.head;
    let result = "";
    while (current) {
        result += current.data + " ⇄ ";
        current = current.next;
    }
    console.log(result + "NULL");
}
```

---

# **5️⃣ Complete Doubly Linked List Implementation**
```js
class Node {
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

    insertAtBeginning(data) {
        let newNode = new Node(data);
        if (!this.head) {
            this.head = this.tail = newNode;
            return;
        }
        newNode.next = this.head;
        this.head.prev = newNode;
        this.head = newNode;
    }

    insertAtEnd(data) {
        let newNode = new Node(data);
        if (!this.head) {
            this.head = this.tail = newNode;
            return;
        }
        this.tail.next = newNode;
        newNode.prev = this.tail;
        this.tail = newNode;
    }

    deleteNode(value) {
        if (!this.head) return;
        if (this.head.data === value) {
            this.head = this.head.next;
            if (this.head) this.head.prev = null;
            return;
        }
        let current = this.head;
        while (current && current.data !== value) {
            current = current.next;
        }
        if (!current) return;
        if (current.next) current.next.prev = current.prev;
        if (current.prev) current.prev.next = current.next;
        if (!current.next) this.tail = current.prev;
    }

    printList() {
        let current = this.head;
        let result = "";
        while (current) {
            result += current.data + " ⇄ ";
            current = current.next;
        }
        console.log(result + "NULL");
    }
}

// Example Usage:
let dll = new DoublyLinkedList();
dll.insertAtEnd(10);
dll.insertAtEnd(20);
dll.insertAtBeginning(5);
dll.printList(); // Output: 5 ⇄ 10 ⇄ 20 ⇄ NULL
```

---

# **🔥 Conclusion**
✅ **Doubly Linked List is useful for:**
- **Bidirectional Traversal**
- **Stacks, Queues, and Undo/Redo operations**
- **More efficient deletion & insertion**  

A **real-world project using DLL** (like a **browser history manager**) 🚀

---

<br>
<br>

# <center>🐍Python



# **📌 Doubly Linked List in Python**
A **Doubly Linked List (DLL)** has nodes containing:
- **Data**
- **Pointer to the next node**
- **Pointer to the previous node**

---

## **1️⃣ Node Class**
Each node stores **data**, **next pointer**, and **prev pointer**.
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
```

---

## **2️⃣ Doubly Linked List Class**
```python
class DoublyLinkedList:
    def __init__(self):
        self.head = None  # Points to first node
        self.tail = None  # Points to last node
```

---

# **3️⃣ Operations on Doubly Linked List**

## **🔹 1. Insert at the Beginning**
### **➡️ Example:**
```
Before: None <- [10] -> None
Insert(5)
After:  None <- [5] <-> [10] -> None
```
### **🔹 Code:**
```python
    def insert_at_beginning(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = self.tail = new_node
            return
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node
```
✅ **Time Complexity:** `O(1)`

---

## **🔹 2. Insert at the End**
### **➡️ Example:**
```
Before: None <- [10] -> None
Insert(20)
After:  None <- [10] <-> [20] -> None
```
### **🔹 Code:**
```python
    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = self.tail = new_node
            return
        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node
```
✅ **Time Complexity:** `O(1)`

---

## **🔹 3. Insert at a Specific Position**
1. Traverse to the position.
2. Insert new node.

### **🔹 Code:**
```python
    def insert_at_position(self, data, position):
        if position == 0:
            self.insert_at_beginning(data)
            return
        
        new_node = Node(data)
        current = self.head
        index = 0
        
        while current and index < position - 1:
            current = current.next
            index += 1
        
        if not current:
            self.insert_at_end(data)
            return
        
        new_node.next = current.next
        new_node.prev = current

        if current.next:
            current.next.prev = new_node
        
        current.next = new_node

        if not new_node.next:
            self.tail = new_node
```
✅ **Time Complexity:** `O(n)`

---

## **🔹 4. Delete a Node by Value**
1. Locate the node.
2. Update pointers to remove it.

### **➡️ Example:**
```
Before: None <- [10] <-> [20] <-> [30] -> None
Delete(20)
After:  None <- [10] <-> [30] -> None
```
### **🔹 Code:**
```python
    def delete_node(self, value):
        if not self.head:
            return

        if self.head.data == value:
            self.head = self.head.next
            if self.head:
                self.head.prev = None
            return

        current = self.head
        while current and current.data != value:
            current = current.next

        if not current:
            return
        
        if current.next:
            current.next.prev = current.prev

        if current.prev:
            current.prev.next = current.next

        if not current.next:
            self.tail = current.prev
```
✅ **Time Complexity:** `O(n)`

---

## **🔹 5. Search for a Node**
Check if a value exists.

### **🔹 Code:**
```python
    def search(self, value):
        current = self.head
        while current:
            if current.data == value:
                return True
            current = current.next
        return False
```
✅ **Time Complexity:** `O(n)`

---

## **🔹 6. Print the Doubly Linked List**
### **🔹 Code:**
```python
    def print_list(self):
        current = self.head
        result = ""
        while current:
            result += str(current.data) + " ⇄ "
            current = current.next
        print(result + "None")
```

---

# **4️⃣ Complete Doubly Linked List Implementation**
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = self.tail = new_node
            return
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = self.tail = new_node
            return
        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node

    def insert_at_position(self, data, position):
        if position == 0:
            self.insert_at_beginning(data)
            return
        new_node = Node(data)
        current = self.head
        index = 0
        while current and index < position - 1:
            current = current.next
            index += 1
        if not current:
            self.insert_at_end(data)
            return
        new_node.next = current.next
        new_node.prev = current
        if current.next:
            current.next.prev = new_node
        current.next = new_node
        if not new_node.next:
            self.tail = new_node

    def delete_node(self, value):
        if not self.head:
            return
        if self.head.data == value:
            self.head = self.head.next
            if self.head:
                self.head.prev = None
            return
        current = self.head
        while current and current.data != value:
            current = current.next
        if not current:
            return
        if current.next:
            current.next.prev = current.prev
        if current.prev:
            current.prev.next = current.next
        if not current.next:
            self.tail = current.prev

    def search(self, value):
        current = self.head
        while current:
            if current.data == value:
                return True
            current = current.next
        return False

    def print_list(self):
        current = self.head
        result = ""
        while current:
            result += str(current.data) + " ⇄ "
            current = current.next
        print(result + "None")

# Example Usage:
dll = DoublyLinkedList()
dll.insert_at_end(10)
dll.insert_at_end(20)
dll.insert_at_beginning(5)
dll.print_list()  # Output: 5 ⇄ 10 ⇄ 20 ⇄ None
```

---

# **🔥 Conclusion**
✅ **Doubly Linked List is useful for:**
- **Bidirectional Traversal**
- **Stacks, Queues, and Undo/Redo operations**
- **Efficient Insertion & Deletion**

implement **a real-world project using DLL** (like a **browser history manager**) 🚀