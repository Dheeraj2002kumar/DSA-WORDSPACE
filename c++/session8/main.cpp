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