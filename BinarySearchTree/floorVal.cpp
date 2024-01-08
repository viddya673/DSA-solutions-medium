#include <iostream>
#include <climits>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

struct TreeNode* newNode(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findFloor(TreeNode* root, int minVal, int maxVal){
    if(!root)
        return minVal;

    if(root->val>maxVal)
        return findFloor(root->left, minVal, maxVal);
    if(root->val<=maxVal)
        return findFloor(root->right, root->val, maxVal);
}

int floorInBST(TreeNode* root, int X)
{
    return findFloor(root, INT_MIN, X);
}

int main(){
    TreeNode* root = newNode(20);
    root->left = newNode(10);
    root->left->left = newNode(5);
    root->left->right = newNode(25);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    cout<<floorInBST(root, 21);
}