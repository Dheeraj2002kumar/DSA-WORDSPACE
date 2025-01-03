/*
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void preorder(struct Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " -> ";
    preorder(root->left);
    preorder(root -> right);
}

void postorder(struct Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " -> ";
}

void inorder(struct Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(30);

    cout << "\n Inorder traversal of binary tree is \n";
    inorder(root);

    cout << "\n Preorder traversal of binary tree is \n";
    preorder(root);

    cout << "\n Postorder traversal of binary tree is \n";
    postorder(root);

    return 0;
}
*/

// --------------- Output ---------------------
// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\c++\Session7> g++ main.cpp -o main
// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\c++\Session7> ./main

//  Inorder traversal of binary tree is 
// 5 -> 12 -> 30 -> 1 -> 9 ->
//  Preorder traversal of binary tree is
// 1 -> 12 -> 5 -> 30 -> 9 ->
//  Postorder traversal of binary tree is
// 5 -> 30 -> 12 -> 9 -> 1 ->





// ++++++++++++++++++++++ Binary Search Tree +++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(struct Node *root){
    if(root != NULL){
        inorder(root->left);
        cout << root->data << " -> ";
        inorder(root->right);
    }
}

int main(){
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(2);
    root->left->right = newNode(7);

    cout << "\n Inorder traversal of binary tree is \n";
    inorder(root);
    return 0;
}

// --------------- Output ---------------------
// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\c++\Session7> g++ main.cpp -o main
// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\c++\Session7> ./main

//  Inorder traversal of binary tree is 
// 2 -> 5 -> 7 -> 10 -> 15 ->