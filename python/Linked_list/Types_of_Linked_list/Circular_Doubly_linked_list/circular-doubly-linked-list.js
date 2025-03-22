class Node {
    constructor(data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class  CircularDoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    insertAtBeginning(data){
        let newNode = new Node(data);
        if (!this.head){
            this.head = this.tail = newNode;
            this.head.next = this.head;
            this.head.prev = this.head;
        } 
        else {
            newNode.next = this.head;
            newNode.prev = this.tail;
            this.head.prev = newNode;
            this.tail.next = newNode;
            this.head = newNode;
        }
    }

    insertAtEnd(data){
        let newNode = new Node(data);
        if (!this.head){
            this.head = this.tail = newNode;
            this.head.next = this.head;
            this.head.prev = this.head
        }
        else{
            newNode.prev = this.tail;
            newNode.next = this.head;
            this.tail.next = newNode;
            this.head.prev = newNode;
            this.tail = newNode;
        }
    }

    
}