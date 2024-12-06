// c++ program implemention of Queue operation
/*
#include<iostream>
#define SIZE 5
using namespace std;

class Queue{
  private:
  int queue[SIZE], front, rear;

  public:
  Queue(){
    // front = rear = -1;
    front = -1;
    rear = -1;
  }

  bool isFull(){
    if(rear == SIZE - 1 && front == 0){
      return true;
    }
    return false;
  }

  bool isEmpty(){
    if(front == -1 && rear == -1){
      return true;
    }
    return false;
  }

  void enqueue(int element){
    if(isFull()){
      cout<<"Queue is full"<<endl;
    }
    else{
      if(front == -1){
        front = 0;
        rear++;
        queue[rear] = element;
        cout << "\nInserted " << element;
      }
    }
  }

  int dequeue(){
    if(isEmpty()){
      cout<<"\nQueue is already empty";
      return -1;
    }else{
      int temp = queue[front];
      if(front >= rear){
        front = rear = -1;
      }else{
        front++;
      }
      cout << "Deleted "<< temp;
      return temp;
    }
  }

  void display(){
    int i;
    if(isEmpty()){
      cout << "\nQueue is empty"<<endl;
    } else{
      cout << "front index"<<front;
      cout << "Queue_Item:: ";
      for(i = front; i <= rear; i++){
        cout << queue[i] << " ";
        cout << "\nrear index "<< rear;
      }
    }
  }
};

int main(){
  Queue q;

  q.dequeue();
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(30);
  q.enqueue(30);
  q.display();
  // q.dequeue();
  // q.dequeue();  
  // q.display();
  return 0;
}

*/


// -------------------------------------------------------

/*
The code I provided implements a simple queue using a linked list. This type of queue is a basic data structure that follows the First In, First Out (FIFO) principle, meaning that the first element added to the queue will be the first one to be removed.

Characteristics of the Queue in the Code:
Linked List Implementation:

The queue is implemented using a linked list, where each node contains data and a pointer to the next node. This allows for dynamic memory allocation, meaning the queue can grow and shrink as needed without a predefined size limit.
Basic Operations:

Enqueue: Adds an element to the rear of the queue.
Dequeue: Removes an element from the front of the queue.
Display: Shows the current elements in the queue.
Dynamic Size:

Unlike an array-based implementation of a queue, which has a fixed size, the linked list implementation can grow and shrink dynamically based on the number of elements.
Types of Queues:
While the provided code implements a basic queue, there are several other types of queues in computer science, including:

Circular Queue: A queue where the last position is connected back to the first position to make a circle. This is often implemented using arrays.

Priority Queue: A special type of queue where each element has a priority. Elements with higher priority are dequeued before elements with lower priority.

Double-Ended Queue (Deque): A queue where elements can be added or removed from both the front and the rear.

Blocking Queue: A type of queue that supports operations that wait for the queue to become non-empty when dequeuing and wait for space to become available when enqueueing.

Concurrent Queue: A queue designed for use in multi-threaded environments, allowing safe access from multiple threads.

The code provided is a straightforward implementation of a basic FIFO queue using a linked list, which is suitable for many applications where simple queue operations are needed.
*/

/*
#include <iostream>

using namespace std;

// Node structure for the queue
struct Node {
    int data;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        cout << value << " enqueued to the queue." << endl;
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicate that the queue is empty
        }

        Node* temp = front;
        int value = front->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr; // If the queue is now empty
        }

        delete temp; // Free the memory of the dequeued node
        cout << value << " dequeued from the queue." << endl;
        return value;
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function to demonstrate queue operations
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Attempt to dequeue from an empty queue

    return 0;
}
*/

// +++++++++++++++++ output ++++++++++++++++++++++++

// PS J:\My Drive\DSA-WORDSPACE\c++\session4> g++ queue.cpp -o queue
// PS J:\My Drive\DSA-WORDSPACE\c++\session4> ./queue
// 10 enqueued to the queue.
// 20 enqueued to the queue.
// 30 enqueued to the queue.
// Queue elements: 10 20 30
// 10 dequeued from the queue.
// Queue elements: 20 30
// 20 enqueued to the queue.
// 30 enqueued to the queue.
// Queue elements: 10 20 30
// 10 dequeued from the queue.
// Queue elements: 20 30
// 20 dequeued from the queue.
// 30 dequeued from the queue.
// Queue is empty. Cannot dequeue.
// PS J:\My Drive\DSA-WORDSPACE\c++\session4>






//  -----------------------------------------------------

/*
Explanation:
Array Implementation: The queue is implemented using a fixed-size array (arr[MAX]), where MAX defines the maximum number of elements the queue can hold.

Front and Rear Pointers:

front: Points to the index of the front element in the queue.
rear: Points to the index of the last element in the queue.
Basic Operations:

Enqueue: Adds an element to the rear of the queue. If the queue is full, it displays a message indicating that the enqueue operation cannot be performed.
Dequeue: Removes an element from the front of the queue. If the queue is empty, it displays a message indicating that the dequeue operation cannot be performed.
Display: Shows the current elements in the queue.
Queue Full and Empty Checks: The program includes checks to determine if the queue is full or empty before performing enqueue and dequeue operations.
*/


#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the queue

class Queue {
private:
    int arr[MAX]; // Array to store queue elements
    int front;    // Index of the front element
    int rear;     // Index of the rear element

public:
    // Constructor to initialize the queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == MAX - 1;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0; // Set front to 0 if the queue was empty
        }
        rear++;
        arr[rear] = value; // Add the new element at the rear
        cout << value << " enqueued to the queue." << endl;
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicate that the queue is empty
        }
        int value = arr[front]; // Get the front element
        if (front >= rear) {
            front = -1; // Reset the queue if it becomes empty
            rear = -1;
        } else {
            front++; // Move front to the next element
        }
        cout << value << " dequeued from the queue." << endl;
        return value;
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function to demonstrate queue operations
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Attempt to dequeue from an empty queue

    return 0;
}