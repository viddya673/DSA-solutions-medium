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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* result = new ListNode();
        ListNode* rptr = result;
        
        int carryforward = 0;
        while (ptr1 || ptr2){
            int value = (ptr1 ? ptr1->val : 0) + (ptr2 ? ptr2->val : 0) + carryforward; 
            carryforward = value/10;
            ListNode* temp = new ListNode();
            temp->val = value%10;
            temp->next = NULL;
            rptr->next = temp;
            rptr = temp;
               
            if (ptr1) ptr1 = ptr1->next;
            if (ptr2) ptr2 = ptr2->next;
        } 
        if (carryforward == 1){
            ListNode* temp = new ListNode();
            temp->val = carryforward;
            temp->next = NULL;
            rptr->next = temp;
            rptr = temp;
        }
        return result->next;
    }
};

int main(){
    ListNode* l1 = new ListNode();
    newNode(l1, 2);
    newNode(l1, 4);
    newNode(l1, 3);

    ListNode* l2 = new ListNode();
    newNode(l2, 5);
    newNode(l2, 6);
    newNode(l2, 4);

    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    while(res){
        cout<<res->val<<endl;
        res = res->next;
    } 
}