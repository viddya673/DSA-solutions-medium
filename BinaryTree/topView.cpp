#include <iostream>
#include <map>
#include <queue> 
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

vector<int> topView(Node* root){
    queue<pair<int, Node*>> q;
    map<int, int> mp;

    q.push({0, root});
    while(!q.empty()){
        pair<int, Node*> curr = q.front();
        q.pop();

        if(!mp[curr.first]){
            mp[curr.first] = curr.second->data;
        }

        if(curr.second->left!=NULL)
            q.push({curr.first-1, curr.second->left});

        if(curr.second->right!=NULL)
            q.push({curr.first+1, curr.second->right});
    }

    vector<int> res;
    for(auto m: mp){
        res.push_back(m.second);
    }
    return res;
}

int main(){
    struct Node* root = newNode(2);
    root->left = newNode(4);
    root->right = newNode(1);
    root->left->left = newNode(7);
    root->right->left = newNode(8);
    root->right->right = newNode(3);

    vector<int> res = topView(root);
    for(int r: res)
        cout<<r<<endl;
}