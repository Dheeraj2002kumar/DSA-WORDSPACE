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

/*
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
*/

// --------------- Output ---------------------
// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\c++\Session7> g++ main.cpp -o main
// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\c++\Session7> ./main

//  Inorder traversal of binary tree is 
// 2 -> 5 -> 7 -> 10 -> 15 ->



// ++++++++++++ full binary tree +++++++++++++++++
/*
#include <iostream>

// Definition of a Node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to create a new node
Node* createNode(int data) {
    return new Node(data);
}

// Function to insert nodes to create a full binary tree
Node* insertFullBinaryTree(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }

    // If the left child is empty, insert the new node there
    if (root->left == nullptr) {
        root->left = createNode(data);
    }
    // If the right child is empty, insert the new node there
    else if (root->right == nullptr) {
        root->right = createNode(data);
    }
    // If both children are present, recursively insert in the left subtree
    else {
        root->left = insertFullBinaryTree(root->left, data);
    }

    return root;
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->data << " -> ";
    inorderTraversal(root->right);
}

// Function to perform preorder traversal of the binary tree
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " -> ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform postorder traversal of the binary tree
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->data << " -> ";
}

int main() {
    Node* root = nullptr;

    // Inserting nodes to create a full binary tree
    root = insertFullBinaryTree(root, 1);
    root = insertFullBinaryTree(root, 2);
    root = insertFullBinaryTree(root, 3);
    root = insertFullBinaryTree(root, 4);
    root = insertFullBinaryTree(root, 5);
    root = insertFullBinaryTree(root, 6);
    root = insertFullBinaryTree(root, 7);

    // Traversing the binary tree
    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    return 0;
}

*/
// ------------------ output ----------------------

// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\c++\Session7> g++ main.cpp -o main
// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\c++\Session7> ./main
// Inorder Traversal: 6 -> 4 -> 7 -> 2 -> 5 -> 1 -> 3 -> 
// Preorder Traversal: 1 -> 2 -> 4 -> 6 -> 7 -> 5 -> 3 ->
// Postorder Traversal: 6 -> 7 -> 4 -> 5 -> 2 -> 3 -> 1 ->











/*

Explanation:
Node Structure: The Node structure represents a node in the binary tree, containing an integer data, and pointers to the left and right children.

createNode Function: This function creates a new node with the given data.

insertFullBinaryTree Function: This function inserts nodes into the binary tree in such a way that the tree remains full. If both children of a node are present, it recursively inserts the new node in the left subtree.

Traversal Functions:

inorderTraversal: Traverses the tree in inorder (left, root, right).
preorderTraversal: Traverses the tree in preorder (root, left, right).
postorderTraversal: Traverses the tree in postorder (left, right, root).
Main Function: The main function creates a full binary tree by inserting nodes and then performs inorder, preorder, and postorder traversals to display the tree's contents.

*/