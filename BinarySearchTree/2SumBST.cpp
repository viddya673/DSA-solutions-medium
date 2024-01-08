#include <iostream>
#include <stack>
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

class BSTiterator{
    private: 
        stack<Node*> stk;
        bool reverse;

        void pushAll(Node* root){
            while(root){
                stk.push(root);
                if(!reverse)
                    root = root->left;
                else
                    root = root->right;
            }
        }

    public:
        BSTiterator(Node* root, bool isReverse){
            reverse = isReverse;
            pushAll(root);
        }

        int next(){
            Node* curr = stk.top();
            stk.pop();
            if (reverse) pushAll(curr->left);
            else pushAll(curr->right);
            return curr->val;
        }
        bool hasNext(){
            return !stk.empty();
        }

};

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

    /* Using BST iterator */
    bool pairSumBst(Node *root, int k)
    {
        BSTiterator l(root, false);
        BSTiterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i<j){
            int sum = i+j;
            if(sum==k) return true;

            if(sum<k){
                i = l.next();
            }
            else if(sum>k){
                j = r.next();
            }
        }
        return false;
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
    cout<<s.findTarget(root, 9)<<endl;
    cout<<s.pairSumBst(root, 9);
}