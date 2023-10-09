#include <iostream>
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
    void returnSum(Node* root, int& sum, int num){
        if(root==NULL)
            return;
        if(!root->left && !root->right){
            num = (num*10)+root->data;
            sum += num;
            num = num/10;
        }
        returnSum(root->left, sum, num*10+root->data);
        returnSum(root->right, sum, num*10+root->data);
    }

    int sumNumbers(Node* root) {
        int num = 0;
        int sum = 0;
        returnSum(root, sum, num); 
        return sum;
    }
};

int main(){
    Node* root = newNode(4);
    root->left = newNode(9);
    root->right = newNode(0);
    root->left->left = newNode(5);
    root->left->right = newNode(1);

    Solution s;
    cout<<s.sumNumbers(root);
}