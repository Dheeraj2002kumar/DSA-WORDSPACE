#include<iostream>
using namespace std;

#define MAX 10

class Deque{
    int arr[MAX];
    int front, rear, size;

    public:
    Deque(){
        front = -1;
        rear = 0;
        this->size = size;
    }

    void insertfront(int key);
    void insertrear(int key);
    void deletefront();
    void deleterear();
    bool isFull();
    bool isEmpty();
    int getFront();
    int getRear();
};

bool Deque::isFull(){
    return ((front == 0 && rear == size-1) || (front == rear + 1));     
}

bool Deque::isEmpty(){
    return (front == -1);
}

void Deque::insertfront(int key){
    if(isFull()){
        cout << "Deque is full (OVERFLOW CONDITION)";
        return;
    }

    if(front == -1){
        front = 0;
        rear = 0;
    }else if (front == 0){
        front = size -1;
    }else{
        front = front - 1;
    }
    arr[front] = key;
}

void Deque::insertrear(int key){
    if(isFull()){
        cout << "Deque is full (OVERFLOW CONDITION)";
        return;
    }

    if(front == -1){
        front = 0;
        rear = 0;
    }else if(rear == size - 1){
        rear = 0;
    } else{
        rear = rear + 1;
    }
    arr[rear] = key;
}

void Deque::deletefront(){
    if(isEmpty()){
        cout << "Deque is empty (UNDERFLOW CONDITION)";
        return;
    }

    if(front == rear){
        front = -1;
        rear = -1;
    }else if(front == size -1){
        front = 0;
    }else{
        front = front + 1;
    }
}

void Deque::deleterear(){
    if(isEmpty()){
        cout << "Deque is empty (UNDERFLOW CONDITION)";
        return;
    }

    if(front == rear){
        front = -1;
        rear = -1;
    } else if(rear == 0){
        rear = size - 1;
    } else{
        rear = rear -1;
    }
}

int Deque::getFront(){
    if(isEmpty()){
        cout << "Deque is empty (UNDERFLOW CONDITION)";
        return -1;
    }
    return arr[front];
}

int Deque::getRear(){
    if(isEmpty() || rear < 0){
        cout << "Deque is empty (UNDERFLOW CONDITION)";
        return -1;
    }
    return arr[rear];
}

int main(){
    Deque dq;
    cout << "\nInsert element at rear end";
    dq.insertrear(10);
    dq.insertrear(20);

    cout << "\nRear Elements " << dq.getRear();

    dq.deleterear();
    cout << "\nRear element: " << dq.getRear();

    dq.insertfront(30);
    cout << "\nFront elements" << dq.getFront();

    return 0;
}


// +++++++++++++++++++ output +++++++++++++++++++
// PS J:\My Drive\DSA-WORDSPACE\c++\Session5> g++ queue.cpp -o queue
// PS J:\My Drive\DSA-WORDSPACE\c++\Session5> ./queue

// Insert element at rear end
// Rear Elements 20
// Rear element: 10
// Front elementsDeque is empty (UNDERFLOW CONDITION)-1
// PS J:\My Drive\DSA-WORDSPACE\c++\Session5> 