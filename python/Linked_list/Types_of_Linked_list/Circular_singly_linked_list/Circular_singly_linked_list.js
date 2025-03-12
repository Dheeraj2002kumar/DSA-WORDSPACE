class Node {
    constructor(data){
        this.data = data;
        this.next = null;
    }
}

class CircularSinglyLinkedList{
    constructor(){
        this.head = null;
        this.tail = null;
    }

    insertAtBeginning(data){
        let newNode = new Node(data);
        if (!this.head){
            this.head = this.tail = newNode;
            this.tail.next = this.head;
        } else {
            newNode.next = this.head;
            this.tail.next = newNode;
            this.head = newNode;
        }
    }

    insertAtEnd(data){
        let newNode = new Node(data);
        if (!this.head){
            this.head = this.tail = newNode;
            this.tail.next = this.head;
        } else {
            this.tail.next = newNode;
            this.tail = newNode;
            this.tail.next = this.head;
        }
    }

    deleteNode(value){
        if (!this.head) return;
        let current = this.head;
        let prev = this.tail;
        while(current.data !== value){
            if (current.next === this.head) return;
            prev = current;
            current = current.next;
        }
        if (current === this.head){
            this.head = this.head.next;
            this.tail.next = this.head;
        } else if (current === this.tail){
            prev.next = this.head;
            this.tail = prev;
        } else {
            prev.next = current.next;
        }
    }

    printList(){
        if (!this.head) return;
        let current = this.head;
        let result = "";
        do {
            result += current.data + " -> ";
            current = current.next;
        } while (current !== this.head);
        console.log(result + "(HEAD");
    }
}

const csll = new CircularSinglyLinkedList();
csll.insertAtEnd(10);
csll.insertAtEnd(20);
csll.insertAtBeginning(5);
csll.printList();  // Output: 5 -> 10 -> 20 -> (HEAD)