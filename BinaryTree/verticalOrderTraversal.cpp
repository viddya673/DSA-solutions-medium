#include <iostream>
#include <queue>
#include <vector>
#include <map>
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

vector<int> verticalOrderTraversal(Node *root)
{
    map<int, vector<int>> mp;
    vector<int> res;
    queue<pair<int, Node*>> q;
    q.push({0, root});

    while(!q.empty()){
        Node* curr_node = q.front().second;
        int val = q.front().first;
        q.pop();

        mp[val].push_back(curr_node->data);

        if(curr_node->left)
            q.push({val-1, curr_node->left});
        if(curr_node->right)
            q.push({val+1, curr_node->right});
    }

    for(auto item: mp){
        for(int data: item.second)
            res.push_back(data);
    }
    return res;
}

int main(){
    Node* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(2);
    root->right->left = newNode(1);
    root->right->left->left = newNode(4);
    root->right->left->right = newNode(6);

    vector<int> res = verticalOrderTraversal(root);
    for(int r: res)
        cout<<r<<endl;
}