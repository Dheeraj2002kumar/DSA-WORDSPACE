// c++ program for linked list

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

int main(){
    //  create node
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    // allocate the memory
    one = new Node();
    two = new Node();
    three = new Node();

    // add value to them
    one->data = 10;
    two->data = 20;
    three->data = 30;

    // connect them
    one->next = two;
    two->next = three;
    three->next = NULL;

    // add head node to one
    head = one;

    // display linked list value
    while(head != NULL){
        cout <<"\nElements " << head->data << endl;
        head= head->next;
    }


    return 0;
}


// ++++++++++++++++++ output +++++++++++++++++++
// PS J:\My Drive\DSA-WORDSPACE\c++\Session5> g++ linked_list.cpp -o linked_list
// PS J:\My Drive\DSA-WORDSPACE\c++\Session5> ./linked_list

// Elements 10

// Elements 20

// Elements 30
// PS J:\My Drive\DSA-WORDSPACE\c++\Session5>

