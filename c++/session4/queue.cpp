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


