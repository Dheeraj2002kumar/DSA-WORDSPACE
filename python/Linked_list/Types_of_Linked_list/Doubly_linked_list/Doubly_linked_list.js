class Node {
    constructor(data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList{
    constructor(){
        this.head = null;
        this.tail = null;
    }

    insertAtBeginning(data){
        let newNode = new Node(data);
        if (!this.head){
            this.head = this.tail = newNode;
            return;
        }
        newNode.next = this.head;
        this.head.prev = newNode;
        this.head = newNode;
    }

    insertAtEnd(data){
        let newNode = new Node(data);
        if (!this.head){
            this.head = this.tail = newNode;
            return;
        }
        this.tail.next = newNode;
        newNode.prev = this.tail;
        this.tail = newNode;
    }

    deleteNode(value){
        if (!this.head) return;
        if (this.head.data === value){
            this.head = this.head.next;
            if (this.head) this.head.prev = null;
            return;
        }
        let current = this.head;
        while (current && current.data !== value){
            current = current.next;
        }

        if (!current) return;
        if (current.next) current.next.prev = current.prev;
        if (current.prev) current.prev.next = current.next;
        if (!current.next) this.tail = current.prev;
    }

    printList(){
        let current = this.head;
        let result = "";
        while (current){
            result += current.data + " ↔️  ";
            current = current.next;
        }
        console.log(result + "Null");
    }
}

let dll = new DoublyLinkedList();
dll.insertAtEnd(10);
dll.insertAtEnd(20);
dll.insertAtBeginning(5);
dll.printList();    // Output: 5 ⇄ 10 ⇄ 20 ⇄ NULL