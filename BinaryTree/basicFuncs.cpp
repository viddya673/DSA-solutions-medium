#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int heightOfBT(Node* root){
    if(root==NULL)
        return 0;
    return max(heightOfBT(root->left), heightOfBT(root->right)) + 1;
}

int sizeOfBT(Node* root){
    if(root==NULL)
        return 0;
    return sizeOfBT(root->left) + sizeOfBT(root->right) + 1;
}

int maxValOfBT(Node* root){
    if(root==NULL)
        return INT_MIN;
    return max(root->data, max(maxValOfBT(root->left), maxValOfBT(root->right)));
}

int minValOfBT(Node* root){
    if(root==NULL)
        return INT_MAX;
    return min(root->data, min(minValOfBT(root->left), minValOfBT(root->right)));
}

int main(){
    struct Node* root = newNode(2);
    root->left = newNode(4);
    root->right = newNode(1);
    root->left->left = newNode(7);
    root->right->left = newNode(8);
    root->right->right = newNode(3);

    cout<<"Height of Tree:"<<heightOfBT(root)<<endl;
    cout<<"Size of Tree:"<<sizeOfBT(root)<<endl;
    cout<<"Maximum value of Tree:"<<maxValOfBT(root)<<endl;
    cout<<"Minimum value of Tree:"<<minValOfBT(root)<<endl;

}