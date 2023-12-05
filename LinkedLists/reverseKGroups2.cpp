#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node* next;
};

void newNode(Node*& head, int val){
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = NULL;
    temp->next = newNode;
}

class Solution{
private:
    pair<Node*, Node*> getReversed(Node* head, int k){
        Node* curr = head;
        Node* prev = NULL;
        Node* nex = NULL;
        while(curr && k!=0){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            k--;
        }
        return make_pair(prev, curr);
    }
public:
    Node *getListAfterReverseOperation(Node *head, int n, int b[]){
        Node* curr = head;
        Node* dummy = new Node();
        Node* dummy1 = dummy;
        for(int i=0; i<n; i++){
            if(!curr) break;
            
            pair<Node*, Node*> res = getReversed(curr, b[i]);
            Node* prev = res.first;
            Node* nex_head = res.second;

            dummy1->next = prev;
            while(dummy1->next) dummy1 = dummy1->next;

            curr = nex_head;
        }
        if(curr) dummy1->next = curr;
        return dummy->next;
    }
};

int main(){
    Node* head = new Node();
    head->val = 0;
    newNode(head, 6);
    newNode(head, 1);
    newNode(head, 5);

    int b[] = {2, 3};

    Solution s;
    Node* res = s.getListAfterReverseOperation(head, 2, b);
    while(res){
        cout<<res->val<<endl;
        res = res->next;
    }
}