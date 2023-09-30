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

int minVal(Node* root){
    int minV = root->data;
    while(root->left!=NULL){
        minV = root->left->data;
        root = root->left;
    }
    return minV;
}

Node* deleteBST(Node* root, int val){
    if(root==NULL)
        return root;
    if(root->data>val)
        root->left = deleteBST(root->left, val);
    else if(root->data<val)
        root->right = deleteBST(root->right, val);
    else{
        if(root->left==NULL)
            return root->right;
        else if(root->right==NULL)
            return root->left;
        
        root->data = minVal(root->right);
        root->right = deleteBST(root->right, root->data);
        
    }
    return root;
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

    Node* root1 = deleteBST(root, 25);
    inorderTrav(root1);
}