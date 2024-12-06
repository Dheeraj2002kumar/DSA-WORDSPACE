// c++ program to implement circular queue operation 


/*
Explanation:
Array Implementation: The circular queue is implemented using a fixed-size array (arr[MAX]), where MAX defines the maximum number of elements the queue can hold.

Front and Rear Pointers:

front: Points to the index of the front element in the queue.
rear: Points to the index of the last element in the queue.
Basic Operations:

Enqueue: Adds an element to the rear of the queue. If the queue is full, it displays a message indicating that the enqueue operation cannot be performed.
Dequeue: Removes an element from the front of the queue. If the queue is empty, it displays a message indicating that the dequeue operation cannot be performed.
Display: Shows the current elements in the queue.
Circular Logic:

The rear and front pointers wrap around using the modulo operator (%). This allows the queue to reuse space when elements are dequeued.
Queue Full and Empty Checks: The program includes checks to determine if the queue is full or empty before performing enqueue and dequeue operations.
*/
#include <iostream>
using namespace std;

#define MAX 5 // Maximum size of the circular queue

class CircularQueue {
private:
    int arr[MAX]; // Array to store queue elements
    int front;    // Index of the front element
    int rear;     // Index of the rear element

public:
    // Constructor to initialize the queue
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX == front;
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
        rear = (rear + 1) % MAX; // Move rear to the next position
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
        if (front == rear) {
            front = -1; // Reset the queue if it becomes empty
            rear = -1;
        } else {
            front = (front + 1) % MAX; // Move front to the next position
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
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break; // Stop when we reach the rear
            i = (i + 1) % MAX; // Move to the next index
        }
        cout << endl;
    }
};

// Main function to demonstrate circular queue operations
int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); // This will fill the queue
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(60); // This will work since it's circular
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue(); // Dequeue remaining elements
    q.dequeue(); // Attempt to dequeue from an empty queue

    return 0;
}


// +++++++++++++++++++ output ++++++++++++++++++++++++

// PS J:\My Drive\DSA-WORDSPACE\c++\session4> g++ circular_queue.cpp -o circular_queue
// PS J:\My Drive\DSA-WORDSPACE\c++\session4> ./circular_queue
// 10 enqueued to the queue.
// 20 enqueued to the queue.
// 30 enqueued to the queue.
// 40 enqueued to the queue.
// 50 enqueued to the queue.
// Queue elements: 10 20 30 40 50 
// 10 dequeued from the queue.
// Queue elements: 20 30 40 50 
// 60 enqueued to the queue.
// Queue elements: 20 30 40 50 60 
// 20 dequeued from the queue.
// 30 dequeued from the queue.
// 40 dequeued from the queue.
// 50 dequeued from the queue.
// 60 dequeued from the queue.
// PS J:\My Drive\DSA-WORDSPACE\c++\session4> 