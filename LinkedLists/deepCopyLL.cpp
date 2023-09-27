#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;


        unordered_map<Node*, Node*> old_to_new;
        Node* curr = head;
        while(curr){
            old_to_new[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr){
            old_to_new[curr]->next = old_to_new[curr->next];
            old_to_new[curr]->random = old_to_new[curr->random];
            curr = curr->next;
        }

        return old_to_new[head];
        // if(head==NULL)
        //     return NULL;

        // if(mp.count(head) != 0)
        //     return mp[head];

        // Node* newNode = new Node(head->val);
        // mp[head] = newNode;
        // newNode->next = copyRandomList(head->next);
        // newNode->random = copyRandomList(head->random);

        // return newNode;
    }
};

int main(){
    Node* root = new Node(7);
    Node* root2 = new Node(13);
    Node* root3 = new Node(11);
    Node* root4 = new Node(10);
    Node* root5 = new Node(1);

    root->next = root2;
    root->random = NULL;
    root2->next = root3;
    root2->random = root;
    root3->next = root4;
    root3->random = root5;
    root4->next = root5;
    root4->random = root3;
    root5->next = NULL;
    root5->random = root;

    Solution s;
    Node* curr = s.copyRandomList(root);
    while(curr){
        cout<<curr->val<<" "<<curr->next->val<<" "<<curr->random->val<<endl;
        if(curr->next)
            curr = curr->next;
        else
            break;
    }

}