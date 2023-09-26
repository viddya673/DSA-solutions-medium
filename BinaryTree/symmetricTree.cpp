#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool isMirror(Node* root1, Node* root2){
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    
    if(root1->val == root2->val)
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);

    return false;
}

bool isSymmetric(Node* root){
    return isMirror(root->left, root->right);
}

int main(){
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    cout<<isSymmetric(root);
}