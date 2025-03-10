class Node {
    constructor(data){
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList {
    constructor(){
        this.head = null;
    }

    insertAtBeginning(data){
        let newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
    }

    insertAtEnd(data){
        let newNode = new Node(data);
        if (!this.head){
            this.head = newNode;
            return;
        }
        let current = this.head;
        while(current.next){
            current = current.next;
        }
        current.next = newNode;
    }

    insertAtPosition(data, position){
        let newNode = new Node(data);
        if (position === 0){
            newNode.next = this.head;
            this.head = newNode;
            return;
        }
        let current = this.head;
        let prev = null;
        let index = 0;
        while(current !== null && index < position){
            prev = current;
            current = current.next;
            index++;
        }
        newNode.next = current;
        prev.next = newNode;
    }

    deleteNode(value){
        if (!this.head) return;
        if (this.head.data === value){
            this.head = this.head.next;
            return;
        }
        let current = this.head;
        let prev = null;
        while (current && current.data !== value){
            prev = current;
            current = current.next;
        }
        if (!current) return;
        prev.next = current.next;
    }

    search(value){
        let current = this.head;
        while (current){
            if (current.data === value) return true;
            current = current.next;
        }
        return false;
    }

    printList(){
        let current = this.head;
        let result = "";
        while(current){
            result += current.data + " ➡️  ";
            current = current.next;
        }
        console.log(result + "NULL");
    }
}

let sll = new SinglyLinkedList();
sll.insertAtEnd(10);
sll.insertAtEnd(20);
sll.insertAtBeginning(5);
sll.printList();   // Output: 5 → 10 → 20 → NULL