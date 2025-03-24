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

    deleteNode(value){
        if (!this.head) return;

        let current = this.head;
        do {
            if (current.data === value){
                if (current === this.head){
                    this.head = this.head.next;
                    this.tail.next = this.head;
                    this.head.prev = this.tail;
                } 
                else if (current === this.tail){
                    this.tail = this.tail.prev;
                    this.tail.next = this.head;
                    this.head.prev = this.tail;
                }
                else {
                    current.prev.next = current.next;
                    current.next.prev = current.prev;
                }
                return;
            }
            current = current.next;
        } while(current !== this.head);
    }

    printList(){
        if (!this.head){
            console.log("List is Empty");
            return;
        }

        let current = this.head;
        let result = "";
        do{
            result += current.data + " ⇄ ";
            current = current.next;
        } while(current !== this.head);
        console.log(result + "(HEAD)");
    }
}

let cdll = new CircularDoublyLinkedList();
cdll.insertAtEnd(10);
cdll.insertAtEnd(20);
cdll.insertAtBeginning(5);
cdll.printList();