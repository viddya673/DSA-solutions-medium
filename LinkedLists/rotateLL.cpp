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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0 || head->next == NULL)    return head;

        ListNode* curr = head;
        int length = 1;

        while(curr->next != NULL) {
            curr = curr->next;
            length++;
        }

        curr->next = head;
        k = k % length;
        k = length - k;
        while(k--)  curr = curr->next;

        head = curr->next;
        curr->next = NULL;

        return head;
    }

    /*My initial approach*/
    // void rotate(ListNode*& head){
    //     ListNode* slow = head;
    //     ListNode* fast = head->next;

    //     while(fast && fast->next){
    //         slow = slow->next;
    //         fast = fast->next;
    //     }

    //     slow->next = NULL;
    //     fast->next = head;
    //     head = fast;
    // }

    // ListNode* rotateRight(ListNode* head, int k) {
    //     if(!head || !head->next)
    //         return head;

    //     int size=0;
    //     ListNode* curr = head;
    //     while(curr){
    //         size += 1;
    //         curr = curr->next;
    //     }
    //     k %= size;

    //     while(k--!=0)
    //         rotate(head);
    //     return head;
    // }
};

int main(){
    ListNode* head = new ListNode();
    newNode(head, 1);
    newNode(head, 2);
    newNode(head, 3);
    newNode(head, 4);
    newNode(head, 5);

    Solution s;
    ListNode* res = s.rotateRight(head, 2);
    while(res){
        cout<<res->val<<endl;
        res = res->next;
    }
}