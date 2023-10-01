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

class Solution {
public:
    void inorder(TreeNode* root, int& ans, int& k){
        if(root!=NULL){
            inorder(root->left, ans, k);
            if(--k==0)
                ans = root->val;
            inorder(root->right, ans, k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0; 
        inorder(root, ans, k);
        return ans;
    }
};

int main(){
    TreeNode* root = newNode(20);
    root->left = newNode(10);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);

    Solution s;
    cout<<s.kthSmallest(root, 2);
}