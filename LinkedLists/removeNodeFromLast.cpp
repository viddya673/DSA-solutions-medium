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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) 
            fast = fast->next;
        
        if (!fast) 
            return head->next;
        
        while (fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};

int main(){
    ListNode* head = new ListNode();
    newNode(head, 1);
    newNode(head, 2);
    newNode(head, 3);
    newNode(head, 4);
    newNode(head, 5);

    Solution s;
    ListNode* res = s.removeNthFromEnd(head, 2);
    while(res){
        cout<<res->val<<endl;
        res = res->next;
    }
}