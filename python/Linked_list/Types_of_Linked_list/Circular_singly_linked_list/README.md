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

