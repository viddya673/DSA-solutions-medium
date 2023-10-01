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

// class Solution {
// public:
//     bool validate(TreeNode* root, long long& prev) {
//         if (root != NULL) {
//             if (!validate(root->left, prev)) {
//                 return false;
//             }
//             if (root->val <= prev) {
//                 return false;
//             }
//             prev = root->val;
//             return validate(root->right, prev);
//         }
//         return true;
//     }
//     bool isValidBST(TreeNode* root) {
//         long long prev = LLONG_MIN;
//         return validate(root, prev);
//     }
// };

class Solution {
public:
    bool validate(TreeNode* root, int mini, int maxi) {
        if(root==NULL)
            return true;

        if(root->val<mini || root->val>maxi)
            return false;

        return (validate(root->left, mini, root->val-1) && validate(root->right, root->val+1, maxi));
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, INT_MIN, INT_MAX);
    }
};

int main(){
    TreeNode* root = newNode(20);
    root->left = newNode(10);
    root->left->left = newNode(5);
    root->left->right = newNode(25);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);

    Solution s;
    cout<<s.isValidBST(root);
}