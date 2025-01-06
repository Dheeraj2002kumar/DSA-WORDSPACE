// perfect binary tree

/*
#include<iostream>
using namespace std;

struct Node{
    int key;
    struct Node *left, *right;
};

int depth(Node *node){
    int d=0;
    while(node != NULL){
        d++;
        node = node->left;
    }
    return d;
}

bool isPerfectR(struct Node *root, int d, int level=0){
    if(root == NULL){
        return true;
    }

    if (root -> left == NULL && root->right == NULL){
        return (d == level+1);
    }

    if(root->left == NULL || root->right == NULL){
        return false;
    }

    return isPerfectR(root->left, d, level+1 &&  isPerfectR(root->right, d, level+1));
}

bool isPerfect(Node *root){
    int d = depth(root);
    return isPerfectR(root, d);
}

struct Node *newNode(int k){
    struct Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

int main(){
    struct Node *root = NULL;
    root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);

    root->left->left = newNode(40);
    root->left->right = newNode(60);

    if(isPerfect(root)){
        cout << "\ntree is perfect binary tree";
    }
    else {
        cout << "\ntree is not perfect binary tree";
    }

    return 0;
}

*/


// ------------- Output ------------------------

// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\c++\session8> g++ main.cpp -o main
// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\c++\session8> ./main              

// tree is not perfect binary tree



//++++++++++++++++++++++++ other method ++++++++++

// full binary tree

#include<iostream>
using namespace std;

struct Node{
    int key;
    struct Node *left, *right;
};

// Function to calculate the depth of the leftmost node
int depth(Node *node){
    int d = 0;
    while(node != NULL){
        d++;
        node = node->left;
    }
    return d;
}

// Function to check if the tree is perfect
bool isPerfectR(struct Node *root, int d, int level = 0){
    if(root == NULL){
        return true;
    }

    if (root->left == NULL && root->right == NULL){
        return (d == level + 1);
    }

    if(root->left == NULL || root->right == NULL){
        return false;
    }

    return isPerfectR(root->left, d, level + 1) && isPerfectR(root->right, d, level + 1);
}

// Wrapper function to check if the tree is perfect
bool isPerfect(Node *root){
    int d = depth(root);
    return isPerfectR(root, d);
}

// Helper function to create a new node
Node* newNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    if(isPerfect(root)){
        cout << "The tree is a perfect binary tree" << endl;
    } else {
        cout << "The tree is not a perfect binary tree" << endl;
    }

    return 0;
}

// ---------- output ----------------

// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\c++\session8> g++ main.cpp -o main
// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\c++\session8> ./main
// The tree is a perfect binary tree