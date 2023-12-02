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

bool helper(Node* root, int V, vector<int>& res){
    if(root){
        if(root->data == V){
            res.push_back(root->data);
            return true;
        }

        res.push_back(root->data);
        if(helper(root->left, V, res) || helper(root->right, V, res)==true) return true;
        res.pop_back();

        return false;
    }
}

vector<int> rootToNodePath(Node* root, int V){
    vector<int> res;
    if(helper(root, V, res)==true);
        return res;
    return res;
}


int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->left = newNode(7);

    vector<int> res = rootToNodePath(root, 7);
    for(int r: res)
        cout<<r<<endl;
}