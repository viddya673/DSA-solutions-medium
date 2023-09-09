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

Node* head = NULL;
Node* prev = NULL;

void flattenToDLL(Node* root, Node*& head, Node*& prev){
    if(root==NULL)
        return;
    flattenToDLL(root->left, head, prev);
    if(!prev)
        head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    flattenToDLL(root->right, head, prev);
}


int main(){
    Node* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(2);
    root->right->left = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(6);


    Node* head = NULL;
    Node* prev = NULL;
    flattenToDLL(root, head, prev);
 
    while(head!=NULL){
        cout<<head->data<<endl;
        head = head->right;
    }
}
