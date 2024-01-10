#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertNode(Node* head, int val){
    if(!head){
        head->data = val;
        return;
    }
    while(head->next){
        head = head->next;
    }
    Node* newNode = new Node();
    newNode->data = val;
    head->next = newNode;
    return;
}

Node* merge(Node* left, Node* right){
    if(!left) return right;
    if(!right) return left;

    Node* res = new Node();
    Node* temp = res;

    while(left && right){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    res = res->next;
    return res;
}
Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* sortList(Node* head){
    if(!head || !head->next) return head;

    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);

    Node* ans = merge(left, right);
    return ans;
}

int main(){
    Node* head = new Node();
    insertNode(head, 1);
    insertNode(head, 9);
    insertNode(head, 3);
    insertNode(head, 8);
    insertNode(head, 4);

    Node* res = sortList(head);
    res = res->next;
    while(res){
        cout<<res->data<<endl;
        res = res->next;
    }
}