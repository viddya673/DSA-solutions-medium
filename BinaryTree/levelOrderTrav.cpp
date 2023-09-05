#include <iostream>
#include <climits>
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

void printLevelOrder(Node* root){
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr==NULL){
            if(!q.empty()){
                q.push(NULL);
                cout<<endl;
                continue;
            }
        }

        cout<<curr->data<<" ";

        if(curr->left != NULL)
            q.push(curr->left);

        if(curr->right != NULL)
            q.push(curr->right);
    }
}

// Recursion
// void printCurrentLevel(Node* root, int level){
//     if(root==NULL)
//         return;
//     if(level==1)
//         cout<<" "<<root->data;
//     else if(level>1){
//         printCurrentLevel(root->left, level-1);
//         printCurrentLevel(root->right, level-1);
//     }
// }

int main(){
    struct Node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(8);
    root->right->right = newNode(3);
    
    // Recursion 
    // for(int i=1; i<=3; i++){
    //     cout<<"Level"<<i<<":";
    //     printCurrentLevel(root, i);
    //     cout<<endl;
    // }

    printLevelOrder(root);
}
