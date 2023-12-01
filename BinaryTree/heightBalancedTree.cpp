#include <iostream>
#include <stack>
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

/* My first approach */
// int findheight(Node* root){
//     if(!root)
//         return 0;

//     int left = findheight(root->left);
//     int right = findheight(root->right);

//     return 1 + max(left, right);
// }
// bool isBalancedBT(Node* root){
//     if(!root) 
//         return true;
    
//     stack<Node*> stk;
//     while(root!=NULL || !stk.empty()){
//         while(root!=NULL){
//             int left = findheight(root->left);
//             int right = findheight(root->right);
//             if(abs(left-right) > 1){
//                 return false;
//             }
//             stk.push(root);
//             root = root->left;
//         }
//         root = stk.top();
//         stk.pop();
//         root = root->right;
//     }  
//     return true;
// }

/* My Second approach */
int maxHeightDifference(Node* root, int& maxDiff){
    if(!root)
        return 0;
    
    int left = maxHeightDifference(root->left, maxDiff);
    int right = maxHeightDifference(root->right, maxDiff);

    maxDiff = max(maxDiff, abs(left-right));

    return 1 + max(left, right);
}

bool isBalancedBT(Node* root){
    int maxDiff = 0;
    maxHeightDifference(root, maxDiff);
    return (maxDiff > 1) ? false : true;
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->left = newNode(7);

    cout<<isBalancedBT(root);
}
