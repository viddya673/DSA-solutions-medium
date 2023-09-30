#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

struct Node* newNode(int val){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool searchBST(Node* root, int val){
    if(root==NULL)
        return false;

    if(root->data == val)
        return true;

    if(val<root->data)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

int main(){
    Node* root = newNode(20);
    root->left = newNode(10);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);

    cout<<searchBST(root, 21);
}
