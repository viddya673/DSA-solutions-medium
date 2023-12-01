#include <stack>
#include <iostream>
#include <vector>
using namespace std;

struct  Node{
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int val){
    struct Node* node = new Node();
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(Node *root, int& diameter) {
    if(!root)
        return 0;
    
    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);

    diameter = max(diameter, leftHeight+rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(Node *root){
	int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->left = newNode(7);

    cout<<diameterOfBinaryTree(root);
}