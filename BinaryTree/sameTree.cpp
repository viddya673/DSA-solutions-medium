#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
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
    vector<int> preOrderTraversal(TreeNode* root){
        vector<int> result;
        if(root!=NULL){
            result.push_back(root->val);
            vector<int> temp1 = preOrderTraversal(root->left);
            for(int t: temp1)
                result.push_back(t);
            vector<int> temp2 = preOrderTraversal(root->right);
            for(int t: temp2)
                result.push_back(t);
        }
        else
            result.push_back(-1);
        return result;
    }


    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> res1 = preOrderTraversal(p);
        vector<int> res2 = preOrderTraversal(q);
        if (res1.size() != res2.size())
            return false;
        
        for(int i=0; i<res1.size(); i++){
            if(res1[i] != res2[i])
                return false;
        }
        return true;
    }
};

int main(){
    struct TreeNode* root = newNode(2);
    root->left = newNode(4);
    root->right = newNode(1);
    root->left->left = newNode(7);
    root->right->left = newNode(8);
    root->right->right = newNode(3);

    struct TreeNode* root2 = newNode(2);
    root2->left = newNode(5);
    root2->right = newNode(1);
    root2->left->left = newNode(7);
    root2->right->left = newNode(8);
    root2->right->right = newNode(3);

    Solution s;
    cout<<s.isSameTree(root, root2);
    return 0;
}