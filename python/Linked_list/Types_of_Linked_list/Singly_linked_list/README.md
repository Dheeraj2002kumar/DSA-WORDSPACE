# **📌 Singly Linked List in JavaScript (JS) - Complete Guide**  

A **Singly Linked List (SLL)** is a linear data structure where each node points to the next node in the sequence. It is one of the fundamental topics in **Data Structures and Algorithms (DSA)** and is frequently asked in **technical interviews**. 🚀  

---

# **1️⃣ What is a Singly Linked List?**
A **Singly Linked List** consists of **nodes**, where each node contains:
- **Data** (value stored in the node)
- **Pointer to the next node**  

📌 Unlike arrays, **linked lists are dynamic** (i.e., they do not require a predefined size).  

### **➡️ Example:**
```
[10] → [20] → [30] → [40] → NULL
```
👉 The last node points to `NULL` (indicating the end of the list).

---

# **2️⃣ Why Use a Singly Linked List?**
🔹 **Efficient Insertions & Deletions**: Unlike arrays, we can insert/delete elements **without shifting elements**.  
🔹 **Dynamic Size**: No need to predefine the size.  
🔹 **No Memory Waste**: Only required memory is allocated.  

📌 **Disadvantages:**  
❌ **Slower Access**: Unlike arrays, accessing an element takes `O(n)` time instead of `O(1)`.  

---

# **3️⃣ Implementation of Singly Linked List in JavaScript**
Let's implement the **Singly Linked List** class with various operations.

## **🔹 Creating a Node Class**
Each node contains **data** and a pointer (`next`) to the next node.

```js
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}
```

## **🔹 Creating a Singly Linked List Class**
```js
class SinglyLinkedList {
    constructor() {
        this.head = null;  // Head points to the first node
    }
}
```

Now, let's add **insertion, deletion, and traversal** functions.

---

# **4️⃣ Operations on Singly Linked List**
## **🔹 1. Insert at the Beginning (Head)**
New node → **becomes the new head**.
### **➡️ Example:**
```
Before:  [10] → [20] → NULL
Insert(5)
After:   [5] → [10] → [20] → NULL
```
### **🔹 Code:**
```js
insertAtBeginning(data) {
    let newNode = new Node(data);
    newNode.next = this.head;  // New node points to current head
    this.head = newNode;       // Update head to the new node
}
```
✅ **Time Complexity:** `O(1)`

---

## **🔹 2. Insert at the End (Tail)**
- Traverse to the last node.
- Add the new node at the end.

### **➡️ Example:**
```
Before:  [10] → [20] → NULL
Insert(30)
After:   [10] → [20] → [30] → NULL
```
### **🔹 Code:**
```js
insertAtEnd(data) {
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
```
✅ **Time Complexity:** `O(n)`

---

## **🔹 3. Insert at a Specific Position**
1. Traverse to the desired position.
2. Insert the new node.

### **🔹 Code:**
```js
insertAtPosition(data, position) {
    let newNode = new Node(data);
    if (position === 0) {
        newNode.next = this.head;
        this.head = newNode;
        return;
    }
    
    let current = this.head;
    let prev = null;
    let index = 0;

    while (current !== null && index < position) {
        prev = current;
        current = current.next;
        index++;
    }

    newNode.next = current;
    prev.next = newNode;
}
```
✅ **Time Complexity:** `O(n)`

---

## **🔹 4. Delete a Node by Value**
1. Find the node with the given value.
2. Remove it from the linked list.

### **➡️ Example:**
```
Before:  [10] → [20] → [30] → NULL
Delete(20)
After:   [10] → [30] → NULL
```
### **🔹 Code:**
```js
deleteNode(value) {
    if (!this.head) return;

    if (this.head.data === value) {
        this.head = this.head.next;
        return;
    }

    let current = this.head;
    let prev = null;

    while (current && current.data !== value) {
        prev = current;
        current = current.next;
    }

    if (!current) return; // Value not found

    prev.next = current.next;
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

## **🔹 6. Print the Linked List**
### **🔹 Code:**
```js
printList() {
    let current = this.head;
    let result = "";
    while (current) {
        result += current.data + " → ";
        current = current.next;
    }
    console.log(result + "NULL");
}
```

---

# **5️⃣ Complete Singly Linked List Implementation**
```js
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

    insertAtBeginning(data) {
        let newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
    }

    insertAtEnd(data) {
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

    insertAtPosition(data, position) {
        let newNode = new Node(data);
        if (position === 0) {
            newNode.next = this.head;
            this.head = newNode;
            return;
        }
        let current = this.head;
        let prev = null;
        let index = 0;
        while (current !== null && index < position) {
            prev = current;
            current = current.next;
            index++;
        }
        newNode.next = current;
        prev.next = newNode;
    }

    deleteNode(value) {
        if (!this.head) return;
        if (this.head.data === value) {
            this.head = this.head.next;
            return;
        }
        let current = this.head;
        let prev = null;
        while (current && current.data !== value) {
            prev = current;
            current = current.next;
        }
        if (!current) return;
        prev.next = current.next;
    }

    search(value) {
        let current = this.head;
        while (current) {
            if (current.data === value) return true;
            current = current.next;
        }
        return false;
    }

    printList() {
        let current = this.head;
        let result = "";
        while (current) {
            result += current.data + " → ";
            current = current.next;
        }
        console.log(result + "NULL");
    }
}

// Example Usage:
let sll = new SinglyLinkedList();
sll.insertAtEnd(10);
sll.insertAtEnd(20);
sll.insertAtBeginning(5);
sll.printList(); // Output: 5 → 10 → 20 → NULL
```

---

# **🔥 Conclusion**
✅ **Singly Linked List is useful for**:  
- **Dynamic memory allocation**
- **Efficient insertions & deletions**  
- **Stacks, queues, and hash chains**  

A **real-world project using Linked Lists** (like a **to-do list or playlist manager**)? 🚀