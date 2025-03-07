# **📌 Complete Guide to Linked Lists in JavaScript**
In this guide, we will cover **everything about Linked Lists**, including:  
✔ **What is a Linked List?**  
✔ **Types of Linked Lists**  
✔ **Operations on Linked Lists (Insert, Delete, Search, Reverse, etc.)**  
✔ **Implementation in JavaScript**  
✔ **Use Cases of Linked Lists in Real-world Projects**  

---

# **📌 1️⃣ What is a Linked List?**
A **Linked List** is a data structure where elements (**nodes**) are **linked** using pointers.  
Each **node** contains:  
- **Data** (the actual value)  
- **Pointer** (reference to the next node)  

Unlike arrays, **linked lists are dynamic** – they grow and shrink in memory as needed.

---

# **📌 2️⃣ Types of Linked Lists**
### ✅ **1. Singly Linked List (SLL)**
Each node points **to the next node only**.  
⏩ **Example:** `A → B → C → D → null`

### ✅ **2. Doubly Linked List (DLL)**
Each node has **two pointers**:  
- One pointing to **the next node**  
- One pointing to **the previous node**  

⏩ **Example:** `null ← A ⇄ B ⇄ C ⇄ D → null`

### ✅ **3. Circular Linked List (CLL)**
The **last node** connects back to the **first node**, forming a loop.  

⏩ **Example:** `A → B → C → D → A (back to start)`

---

# **📌 3️⃣ Singly Linked List Implementation in JavaScript**
We will build a **Singly Linked List** with these operations:
- **Insert (at head, tail, middle)**
- **Delete (from head, tail, middle)**
- **Search**
- **Reverse**
- **Display (print all elements)**

---

## **🔹 Step 1: Define a Node**
Each **node** stores `data` and a `next` pointer.

```js
class Node {
  constructor(value) {
    this.value = value;
    this.next = null; // Pointer to the next node
  }
}
```

---

## **🔹 Step 2: Create a Linked List Class**
This class will manage operations on the linked list.

```js
class LinkedList {
  constructor() {
    this.head = null; // Start of the linked list
  }
}
```

---

## **🔹 Step 3: Insert at the Beginning**
Time Complexity: **O(1)**
```js
insertAtHead(value) {
  let newNode = new Node(value);
  newNode.next = this.head; // Point to the current head
  this.head = newNode; // Update head to new node
}
```

### **🔹 Example Usage**
```js
let list = new LinkedList();
list.insertAtHead(10);
list.insertAtHead(20);
list.insertAtHead(30);
```
✅ **List now:** `30 → 20 → 10 → null`

---

## **🔹 Step 4: Insert at the End**
Time Complexity: **O(n)** (we must traverse the list)
```js
insertAtTail(value) {
  let newNode = new Node(value);
  if (!this.head) {
    this.head = newNode;
    return;
  }
  let temp = this.head;
  while (temp.next !== null) {
    temp = temp.next;
  }
  temp.next = newNode; // Attach new node
}
```

### **🔹 Example Usage**
```js
list.insertAtTail(40);
```
✅ **List now:** `30 → 20 → 10 → 40 → null`

---

## **🔹 Step 5: Insert at a Specific Position**
Time Complexity: **O(n)**
```js
insertAtPosition(value, pos) {
  let newNode = new Node(value);
  if (pos === 0) {
    this.insertAtHead(value);
    return;
  }

  let temp = this.head;
  let i = 0;
  while (temp !== null && i < pos - 1) {
    temp = temp.next;
    i++;
  }

  if (!temp) return console.log("Position out of bounds");

  newNode.next = temp.next;
  temp.next = newNode;
}
```

### **🔹 Example Usage**
```js
list.insertAtPosition(25, 2);
```
✅ **List now:** `30 → 20 → 25 → 10 → 40 → null`

---

## **🔹 Step 6: Delete from the Beginning**
Time Complexity: **O(1)**
```js
deleteAtHead() {
  if (!this.head) return console.log("List is empty");
  this.head = this.head.next; // Move head to next node
}
```

### **🔹 Example Usage**
```js
list.deleteAtHead();
```
✅ **List now:** `20 → 25 → 10 → 40 → null`

---

## **🔹 Step 7: Delete from the End**
Time Complexity: **O(n)**
```js
deleteAtTail() {
  if (!this.head) return console.log("List is empty");
  if (!this.head.next) {
    this.head = null;
    return;
  }
  
  let temp = this.head;
  while (temp.next.next !== null) {
    temp = temp.next;
  }
  temp.next = null; // Remove last node
}
```

### **🔹 Example Usage**
```js
list.deleteAtTail();
```
✅ **List now:** `20 → 25 → 10 → null`

---

## **🔹 Step 8: Delete at a Specific Position**
Time Complexity: **O(n)**
```js
deleteAtPosition(pos) {
  if (pos === 0) {
    this.deleteAtHead();
    return;
  }

  let temp = this.head;
  let i = 0;
  while (temp !== null && i < pos - 1) {
    temp = temp.next;
    i++;
  }

  if (!temp || !temp.next) return console.log("Position out of bounds");

  temp.next = temp.next.next; // Skip the node
}
```

### **🔹 Example Usage**
```js
list.deleteAtPosition(1);
```
✅ **List now:** `20 → 10 → null`

---

## **🔹 Step 9: Search for a Value**
Time Complexity: **O(n)**
```js
search(value) {
  let temp = this.head;
  while (temp !== null) {
    if (temp.value === value) return true;
    temp = temp.next;
  }
  return false;
}
```

### **🔹 Example Usage**
```js
console.log(list.search(10)); // ✅ true
console.log(list.search(50)); // ❌ false
```

---

## **🔹 Step 10: Reverse the Linked List**
Time Complexity: **O(n)**
```js
reverse() {
  let prev = null;
  let current = this.head;
  let next = null;

  while (current !== null) {
    next = current.next; // Save next node
    current.next = prev; // Reverse pointer
    prev = current;
    current = next;
  }
  this.head = prev; // Update head
}
```

### **🔹 Example Usage**
```js
list.reverse();
```
✅ **List now (reversed):** `10 → 20 → null`

---

# **📌 4️⃣ Use Cases of Linked Lists in Real-world Projects**
### ✅ **1. Managing Browser History (Back/Forward)**
- Web browsers use **Doubly Linked Lists** for history navigation.

### ✅ **2. Implementing Undo/Redo**
- Text editors use **Linked Lists** to track changes.

### ✅ **3. Memory Management**
- Operating systems use **Linked Lists** to manage RAM allocation.

### ✅ **4. Real-time Gaming**
- Game objects (e.g., bullets, enemies) are dynamically stored using **Linked Lists**.

---

# **🚀 Final Summary**
| **Operation**  | **Time Complexity** |
|--------------|----------------|
| Insert at Head  | O(1) |
| Insert at Tail  | O(n) |
| Delete at Head  | O(1) |
| Delete at Tail  | O(n) |
| Search | O(n) |
| Reverse | O(n) |

---

Sure! Below is a complete implementation of a **Singly Linked List** in Python, including all major operations such as **insertion, deletion, searching, and reversing**.  

---

## **📌 Python Implementation of Singly Linked List**
```python
# Define a Node class
class Node:
    def __init__(self, value):
        self.value = value  # Store data
        self.next = None  # Pointer to the next node

# Define the LinkedList class
class LinkedList:
    def __init__(self):
        self.head = None  # Head of the linked list

    # Insert at the beginning
    def insert_at_head(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node

    # Insert at the end
    def insert_at_tail(self, value):
        new_node = Node(value)
        if not self.head:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

    # Insert at a specific position
    def insert_at_position(self, value, position):
        if position == 0:
            self.insert_at_head(value)
            return
        new_node = Node(value)
        temp = self.head
        for _ in range(position - 1):
            if temp is None:
                print("Position out of bounds")
                return
            temp = temp.next
        new_node.next = temp.next
        temp.next = new_node

    # Delete from the beginning
    def delete_at_head(self):
        if not self.head:
            print("List is empty")
            return
        self.head = self.head.next

    # Delete from the end
    def delete_at_tail(self):
        if not self.head:
            print("List is empty")
            return
        if not self.head.next:
            self.head = None
            return
        temp = self.head
        while temp.next.next:
            temp = temp.next
        temp.next = None

    # Delete at a specific position
    def delete_at_position(self, position):
        if position == 0:
            self.delete_at_head()
            return
        temp = self.head
        for _ in range(position - 1):
            if temp is None or temp.next is None:
                print("Position out of bounds")
                return
            temp = temp.next
        temp.next = temp.next.next

    # Search for an element
    def search(self, value):
        temp = self.head
        while temp:
            if temp.value == value:
                return True
            temp = temp.next
        return False

    # Reverse the linked list
    def reverse(self):
        prev = None
        current = self.head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev

    # Print the linked list
    def display(self):
        temp = self.head
        while temp:
            print(temp.value, end=" → ")
            temp = temp.next
        print("None")

# Example Usage
ll = LinkedList()
ll.insert_at_head(10)
ll.insert_at_head(20)
ll.insert_at_tail(30)
ll.insert_at_position(25, 2)
ll.display()  # Output: 20 → 10 → 25 → 30 → None

ll.delete_at_head()
ll.display()  # Output: 10 → 25 → 30 → None

ll.delete_at_tail()
ll.display()  # Output: 10 → 25 → None

print(ll.search(25))  # Output: True
print(ll.search(40))  # Output: False

ll.reverse()
ll.display()  # Output: 25 → 10 → None
```

---

## **📌 Explanation of Functions**
| **Function**           | **Description**                                | **Time Complexity** |
|----------------------|--------------------------------|----------------|
| `insert_at_head(value)` | Inserts a node at the beginning  | O(1) |
| `insert_at_tail(value)` | Inserts a node at the end  | O(n) |
| `insert_at_position(value, pos)` | Inserts a node at a specific position | O(n) |
| `delete_at_head()` | Deletes the first node | O(1) |
| `delete_at_tail()` | Deletes the last node | O(n) |
| `delete_at_position(pos)` | Deletes a node at a specific position | O(n) |
| `search(value)` | Searches for a value in the list | O(n) |
| `reverse()` | Reverses the linked list | O(n) |
| `display()` | Prints all elements of the linked list | O(n) |

---

## **📌 Use Cases of Linked Lists**
✔ **Dynamic Memory Allocation** – Unlike arrays, linked lists can dynamically grow and shrink.  
✔ **Undo & Redo Functionality** – Used in text editors and software applications.  
✔ **Music Playlists** – A doubly linked list can be used to store songs in a queue.  
✔ **Cache Implementation (LRU Cache)** – Linked lists are used in caching mechanisms.

