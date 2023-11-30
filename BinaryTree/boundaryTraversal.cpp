/*Boundary traversal in anti-clockwise*/
#include <iostream>
#include <vector>
#include <unordered_map>
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

bool isLeaf(Node* root){
    return (!root->left && !root->right);
}

vector<int> getLeftmost(Node* root){
    Node* curr = root->left;
    vector<int> res;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
    return res;
}

vector<int> getRightmost(Node* root){
    Node* curr = root->right;
    vector<int> res;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    return res;
}

void getLeafNodes(Node* root, vector<int>& res){
    if (isLeaf(root)) {
        res.push_back(root -> data);
        return;
    }
    if (root -> left) getLeafNodes(root -> left, res);
    if (root -> right) getLeafNodes(root -> right, res);
}

vector<int> traverseBoundary(Node *root)
{
	vector<int> left = getLeftmost(root);
    vector<int> leaves;
    getLeafNodes(root, leaves);
    vector<int> right = getRightmost(root);

    vector<int> result;
    result.push_back(root->data);
    for(int l: left)
        result.push_back(l);
    for(int le: leaves)
        result.push_back(le);
    int n = right.size();
    for(int i=n-1; i>=0; i--)
        result.push_back(right[i]);

    return result;
}

int main(){
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(3);
    root->left->right = newNode(8);
    root->left->right->left = newNode(7);
    root->right->left = newNode(18);
    root->right->right = newNode(25);

    vector<int> res = traverseBoundary(root);
    for(int r: res)
        cout<<r<<endl;
}