#include <iostream>
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

void flatten(Node* root){
    if(root==NULL)
        return;
    Node* curr = root;

    while(curr){
        if(curr->left){
            Node* rightMost = curr->left;
            while(rightMost->right)
                rightMost = rightMost->right;
            rightMost->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

int main(){
    Node* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(2);
    root->right->left = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(6);

    flatten(root);
    while(root != NULL){
        cout<<root->data<<endl;
        root = root->right;
    }
}