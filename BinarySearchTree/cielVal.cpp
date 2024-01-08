#include <iostream>
#include <climits>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

struct TreeNode* newNode(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int helper(TreeNode* root, int minVal, int maxVal){
    if(!root)
        return maxVal;

    if(root->data<minVal)
        return helper(root->right, minVal, maxVal);
    if(root->data>=minVal)
        return helper(root->left, minVal, root->data);
}

int findCeil(TreeNode *node, int x){
    return helper(node, x, -1);
}

int main(){
    TreeNode* root = newNode(20);
    root->left = newNode(10);
    root->left->left = newNode(5);
    root->left->right = newNode(25);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    cout<<findCeil(root, 21);
}