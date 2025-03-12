## **📌 Circular Singly Linked List (CSLL) in JavaScript**
A **Circular Singly Linked List (CSLL)** is a variation of a **Singly Linked List (SLL)** where:
- The **last node** points back to the **first node** instead of `null`.
- This forms a **circular connection**.
- Useful in scenarios like **buffered data streaming, scheduling, and round-robin processing**.

---

## **1️⃣ Structure of a Circular Singly Linked List**
- **Each node** contains:
  - `data`: Stores the value.
  - `next`: Pointer to the next node.
- **Last node's next** points back to **head**, making it circular.

---

## **2️⃣ Implementing Circular Singly Linked List in JavaScript**
Let's define a **Node** class first.

### **🔹 Node Class**
```javascript
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}
```

---

## **3️⃣ Circular Singly Linked List Class**
### **🔹 CSLL Class**
```javascript
class CircularSinglyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
  }
}
```

---

# **4️⃣ Operations on Circular Singly Linked List**
## **🔹 1. Insert at the Beginning**
**Steps:**
1. Create a new node.
2. If **list is empty**, set `head` and `tail` to the new node, and make it circular (`tail.next = head`).
3. Otherwise:
   - Point new node's `next` to `head`.
   - Move `tail.next` to new node.
   - Update `head` to new node.

### **🔹 Code:**
```javascript
  insertAtBeginning(data) {
    let newNode = new Node(data);
    
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
      this.tail.next = this.head; // Make it circular
    } else {
      newNode.next = this.head;
      this.tail.next = newNode;
      this.head = newNode;
    }
  }
```
✅ **Time Complexity:** `O(1)`

---

## **🔹 2. Insert at the End**
**Steps:**
1. Create a new node.
2. If **list is empty**, set `head` and `tail` to new node.
3. Otherwise:
   - Set `tail.next` to new node.
   - Update `tail` to new node.
   - Make it circular (`tail.next = head`).

### **🔹 Code:**
```javascript
  insertAtEnd(data) {
    let newNode = new Node(data);

    if (!this.head) {
      this.head = this.tail = newNode;
      this.tail.next = this.head; // Circular connection
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
      this.tail.next = this.head;
    }
  }
```
✅ **Time Complexity:** `O(1)`

---

## **🔹 3. Insert at a Specific Position**
**Steps:**
1. Traverse to the **position - 1** node.
2. Insert new node and update pointers.
3. If inserting at `0`, call `insertAtBeginning()`.
4. If inserting at the end, call `insertAtEnd()`.

### **🔹 Code:**
```javascript
  insertAtPosition(data, position) {
    if (position === 0) {
      this.insertAtBeginning(data);
      return;
    }

    let newNode = new Node(data);
    let current = this.head;
    let index = 0;

    while (current.next !== this.head && index < position - 1) {
      current = current.next;
      index++;
    }

    newNode.next = current.next;
    current.next = newNode;

    if (newNode.next === this.head) {
      this.tail = newNode;
    }
  }
```
✅ **Time Complexity:** `O(n)`

---

## **🔹 4. Delete a Node by Value**
**Steps:**
1. **If the list is empty**, return.
2. **If deleting head**, move head to next node & update `tail.next`.
3. **Otherwise**, find the previous node of the target node and update pointers.
4. **If deleting the last node**, update `tail`.

### **🔹 Code:**
```javascript
  deleteNode(value) {
    if (!this.head) return;

    let current = this.head;
    let prev = this.tail;

    while (current.data !== value) {
      if (current.next === this.head) return; // Value not found
      prev = current;
      current = current.next;
    }

    if (current === this.head) {
      this.head = this.head.next;
      this.tail.next = this.head;
    } else if (current === this.tail) {
      prev.next = this.head;
      this.tail = prev;
    } else {
      prev.next = current.next;
    }
  }
```
✅ **Time Complexity:** `O(n)`

---

## **🔹 5. Search for a Node**
Iterate through the list and check if **data matches**.

### **🔹 Code:**
```javascript
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

## **🔹 6. Print the Circular Linked List**
We use a **do-while loop** to traverse **circularly**.

### **🔹 Code:**
```javascript
  printList() {
    if (!this.head) {
      console.log("List is empty");
      return;
    }

    let current = this.head;
    let result = "";

    do {
      result += current.data + " -> ";
      current = current.next;
    } while (current !== this.head);

    console.log(result + "(HEAD)");
  }
```

---

## **5️⃣ Complete Circular Singly Linked List Code**
```javascript
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class CircularSinglyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  insertAtBeginning(data) {
    let newNode = new Node(data);
    if (!this.head) {
      this.head = this.tail = newNode;
      this.tail.next = this.head;
    } else {
      newNode.next = this.head;
      this.tail.next = newNode;
      this.head = newNode;
    }
  }

  insertAtEnd(data) {
    let newNode = new Node(data);
    if (!this.head) {
      this.head = this.tail = newNode;
      this.tail.next = this.head;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
      this.tail.next = this.head;
    }
  }

  deleteNode(value) {
    if (!this.head) return;
    let current = this.head;
    let prev = this.tail;
    while (current.data !== value) {
      if (current.next === this.head) return;
      prev = current;
      current = current.next;
    }
    if (current === this.head) {
      this.head = this.head.next;
      this.tail.next = this.head;
    } else if (current === this.tail) {
      prev.next = this.head;
      this.tail = prev;
    } else {
      prev.next = current.next;
    }
  }

  printList() {
    if (!this.head) return;
    let current = this.head;
    let result = "";
    do {
      result += current.data + " -> ";
      current = current.next;
    } while (current !== this.head);
    console.log(result + "(HEAD)");
  }
}

// Example Usage
const csll = new CircularSinglyLinkedList();
csll.insertAtEnd(10);
csll.insertAtEnd(20);
csll.insertAtBeginning(5);
csll.printList(); // Output: 5 -> 10 -> 20 -> (HEAD)
```

---

### **🔥 Conclusion**
- **CSLL** is **efficient** in round-robin, streaming, and scheduling applications.
- **Best use cases:** Music playlists, CPU scheduling, Multiplayer games.

<br>
<br>

# <center>🐍Python


## **📌 Circular Singly Linked List (CSLL) in Python**
A **Circular Singly Linked List** is a **linked list** where:
- The **last node** points back to the **first node** instead of `None`.
- This forms a **circular structure**.
- It is used in **buffered streaming, scheduling, and round-robin tasks**.

---

## **1️⃣ Node Class**
Each **node** contains:
- `data`: Stores the value.
- `next`: Pointer to the next node.

### **🔹 Code:**
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
```

---

## **2️⃣ Circular Singly Linked List Class**
Contains:
- `head`: First node in the list.
- `tail`: Last node (points back to `head`).

### **🔹 Code:**
```python
class CircularSinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
```

---

## **3️⃣ Operations on Circular Singly Linked List**
### **🔹 1. Insert at the Beginning**
**Steps:**
1. Create a new node.
2. If **list is empty**, set `head` and `tail` to new node (`tail.next = head`).
3. Otherwise:
   - Point new node's `next` to `head`.
   - Move `tail.next` to new node.
   - Update `head` to new node.

### **🔹 Code:**
```python
    def insert_at_beginning(self, data):
        new_node = Node(data)
        
        if not self.head:
            self.head = self.tail = new_node
            self.tail.next = self.head  # Make it circular
        else:
            new_node.next = self.head
            self.tail.next = new_node
            self.head = new_node
```
✅ **Time Complexity:** `O(1)`

---

### **🔹 2. Insert at the End**
**Steps:**
1. Create a new node.
2. If **list is empty**, set `head` and `tail` to new node.
3. Otherwise:
   - Set `tail.next` to new node.
   - Update `tail` to new node.
   - Make it circular (`tail.next = head`).

### **🔹 Code:**
```python
    def insert_at_end(self, data):
        new_node = Node(data)
        
        if not self.head:
            self.head = self.tail = new_node
            self.tail.next = self.head
        else:
            self.tail.next = new_node
            self.tail = new_node
            self.tail.next = self.head
```
✅ **Time Complexity:** `O(1)`

---

### **🔹 3. Delete a Node by Value**
**Steps:**
1. **If the list is empty**, return.
2. **If deleting head**, move `head` to next node & update `tail.next`.
3. **Otherwise**, find the previous node of the target node and update pointers.
4. **If deleting the last node**, update `tail`.

### **🔹 Code:**
```python
    def delete_node(self, value):
        if not self.head:
            return

        current = self.head
        prev = self.tail

        while current.data != value:
            if current.next == self.head:
                return  # Value not found
            prev = current
            current = current.next

        if current == self.head:
            self.head = self.head.next
            self.tail.next = self.head
        elif current == self.tail:
            prev.next = self.head
            self.tail = prev
        else:
            prev.next = current.next
```
✅ **Time Complexity:** `O(n)`

---

### **🔹 4. Search for a Node**
Iterate through the list and check if **data matches**.

### **🔹 Code:**
```python
    def search(self, value):
        if not self.head:
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

### **🔹 5. Print the Circular Linked List**
We use a **while loop** to traverse **circularly**.

### **🔹 Code:**
```python
    def print_list(self):
        if not self.head:
            print("List is empty")
            return

        current = self.head
        result = ""

        while True:
            result += str(current.data) + " -> "
            current = current.next
            if current == self.head:
                break

        print(result + "(HEAD)")
```

---

## **4️⃣ Complete Circular Singly Linked List Code**
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularSinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = self.tail = new_node
            self.tail.next = self.head
        else:
            new_node.next = self.head
            self.tail.next = new_node
            self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = self.tail = new_node
            self.tail.next = self.head
        else:
            self.tail.next = new_node
            self.tail = new_node
            self.tail.next = self.head

    def delete_node(self, value):
        if not self.head:
            return

        current = self.head
        prev = self.tail

        while current.data != value:
            if current.next == self.head:
                return  # Value not found
            prev = current
            current = current.next

        if current == self.head:
            self.head = self.head.next
            self.tail.next = self.head
        elif current == self.tail:
            prev.next = self.head
            self.tail = prev
        else:
            prev.next = current.next

    def search(self, value):
        if not self.head:
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
        if not self.head:
            print("List is empty")
            return

        current = self.head
        result = ""

        while True:
            result += str(current.data) + " -> "
            current = current.next
            if current == self.head:
                break

        print(result + "(HEAD)")

# Example Usage
csll = CircularSinglyLinkedList()
csll.insert_at_end(10)
csll.insert_at_end(20)
csll.insert_at_beginning(5)
csll.print_list()  # Output: 5 -> 10 -> 20 -> (HEAD)
```

---

### **🔥 Conclusion**
- **Circular Singly Linked List (CSLL)** is efficient for **round-robin scheduling, buffer streaming, and music playlists**.
- **Best Use Cases:**
  - **OS scheduling** (round-robin).
  - **Streaming data** (audio/video buffering).
  - **Multiplayer games** (player turns).

---

