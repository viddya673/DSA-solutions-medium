#include <queue>
#include <iostream>
#include <vector>
using namespace std;

struct  Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val){
    struct Node* node = new Node();
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> temp(levelSize);

            for (int i = 0; i < levelSize; i++) {
                Node* curr = q.front();
                q.pop();

                int ind = (leftToRight) ? i : levelSize-i-1;

                temp[ind] = curr->data;
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            leftToRight = !leftToRight;
            res.push_back(temp);
        }
        return res;
    }
};

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->left = newNode(7);

    Solution s;
    vector<vector<int>> res = s.zigzagLevelOrder(root);
    for(auto r: res){
        for(int i: r){
            cout<<i<<" ";
        }
        cout<<endl;
    }
} 