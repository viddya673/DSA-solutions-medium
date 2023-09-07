#include <iostream>
#include <vector>
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

void getLeftView(Node* root, vector<int>& arr, int level){
    if(root==NULL)
        return;

    if(arr.size()<=level)
        arr.push_back(root->data);
    
    getLeftView(root->left, arr, level+1);
    getLeftView(root->right, arr, level+1);
}

int main(){
    struct Node* root = newNode(2);
    root->left = newNode(4);
    root->right = newNode(1);
    root->left->left = newNode(7);
    root->right->left = newNode(8);
    root->right->right = newNode(3);

    vector<int> arr;
    getLeftView(root, arr, 0);
    for(int a: arr)
        cout<<a<<endl;
}
