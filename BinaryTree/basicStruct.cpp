#include <iostream>
#include <stack>
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

void inOrderTraversal(struct Node* root){
    if(root != NULL){
        inOrderTraversal(root->left);
        cout<<root->data<<endl;
        inOrderTraversal(root->right);
    }
}

void inorderItr(struct Node* root){
    stack<Node*> stk;
    while(root!=NULL || !stk.empty()){
        while(root!=NULL){
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        cout<<root->data<<endl;
        root = root->right;
    }
}

void preOrderTraversal(struct Node* root){
    if(root != NULL){
        cout<<root->data<<endl;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void preorderItr(struct Node* root){
    stack<Node*> stk;
    while(root!=NULL || !stk.empty()){
        while(root!=NULL){
            cout<<root->data<<endl;
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        root = root->right;
    }
} 

void postOrderTraversal(struct Node* root){
    if(root != NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<endl;
    }
}

int main(){
    struct Node* root = newNode(2);
    root->left = newNode(4);
    root->right = newNode(1);
    root->left->left = newNode(7);
    root->right->left = newNode(8);
    root->right->right = newNode(3);

    cout<<"Pre order:"<<endl;
    preOrderTraversal(root);
    cout<<"Pre order iterative:"<<endl;
    preorderItr(root);
    // cout<<"Pre order:"<<endl;
    // preOrderTraversal(root);
    // cout<<"Post order:"<<endl;
    // postOrderTraversal(root);

}