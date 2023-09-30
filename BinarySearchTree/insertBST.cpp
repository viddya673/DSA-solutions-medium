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

void insertBST(Node*& root, int val){
    if(root==NULL){
        Node* temp = newNode(val);
        root = temp;
        return;
    }
    if(val<root->data)
        return insertBST(root->left, val);
    if(val>root->data)
        return insertBST(root->right, val);
}

void inorderTrav(Node* root){
    if(root!=NULL){
        inorderTrav(root->left);
        cout<<root->data<<endl;
        inorderTrav(root->right);
    }
}

int main(){
    Node* root = newNode(20);
    root->left = newNode(10);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);

    insertBST(root, 21);
    inorderTrav(root);

}