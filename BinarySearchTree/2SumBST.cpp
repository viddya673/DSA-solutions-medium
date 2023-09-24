#include <iostream>
#include <unordered_set>
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

class Solution {
public:
    bool solve(unordered_set<int>& seen, Node* root, int k){
        if(root==NULL)
            return false;
        if(seen.count(k-root->val))
            return true;

        seen.insert(root->val);
        return solve(seen, root->left, k) || solve(seen, root->right, k);
    }

    bool findTarget(Node* root, int k) {
        unordered_set<int> seen;
        return solve(seen, root, k);
    }
};

int main(){
    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->right = newNode(7);

    Solution s;
    cout<<s.findTarget(root, 9);
}