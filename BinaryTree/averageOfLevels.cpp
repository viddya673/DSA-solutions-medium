#include <iostream>
#include <queue>
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> level;

        while(!q.empty()){
            double n = q.size();

            double curr_sum=0;
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                curr_sum += curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            double avg = curr_sum/n;
            level.push_back(avg);
        }

        return level;
    }
};


int main(){
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    Solution s;
    vector<double> avgs = s.averageOfLevels(root);
    for(auto x: avgs)
        cout<<x<<endl;
}