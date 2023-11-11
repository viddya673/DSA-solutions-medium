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

void solver(Node* root, string temp, vector<string>& res){
    if(!root)
        return;
    if(!root->left && !root->right){
        temp.append(to_string(root->data)+" ");
        res.push_back(temp);
        return;
    }

    temp.append(to_string(root->data)+" ");
    solver(root->left, temp, res);
    solver(root->right, temp, res);

}

vector <string> allRootToLeaf(Node* root) {
    string temp;
    vector<string> res;
    solver(root, temp, res);
    return res;
}

int main(){
    Node* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(2);
    root->right->left = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(6);

    vector<string> res = allRootToLeaf(root);
    for(string r: res)
        cout<<r<<endl;
}