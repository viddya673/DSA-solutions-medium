#include <iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
};

void newNode(ListNode*& head, int val){
    ListNode* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    ListNode* newNode = new ListNode();
    newNode->val = val;
    newNode->next = NULL;
    temp->next = newNode;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Iterative approach
        // if(head == NULL||head->next == NULL) return head;
        // ListNode* temp = head;
        // int len = 0;
        // while(temp){
        //     temp = temp->next;
        //     len++; 
        // }

        // ListNode* dummy = new ListNode();
        // dummy->next = head;

        // ListNode* prev = dummy;
        // ListNode* curr;
        // ListNode* nex;
        // while(len>=k){
        //     curr = prev->next;
        //     nex = curr->next;
        //     for(int i=1; i<k; i++){
        //         curr->next = nex->next;
        //         nex->next = prev->next;
        //         prev->next = nex;
        //         nex = curr->next;
        //     }
        //     prev = curr;
        //     len -= k;
        // }
        // return dummy->next;

        // Recursive approach
        int count = 0;
        ListNode* temp = head;

        while(temp && count<k){
            temp = temp->next;
            count++;
        }

        if(count<k)
            return head;
        
        temp = head;
        ListNode* prev = NULL;
        for(int i=0; i<k; i++){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        head->next = reverseKGroup(temp, k);
        return prev;
    }
};

int main(){
    ListNode* head = new ListNode();
    head->val = 1;
    newNode(head, 2);
    newNode(head, 3);
    newNode(head, 4);
    newNode(head, 5);

    Solution s;
    ListNode* res = s.reverseKGroup(head, 2);
    while(res){
        cout<<res->val<<endl;
        res = res->next;
    }
}