#include <iostream>
#include <map>
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

    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* temp = head;
        ListNode* prev = NULL;
        map<int, int> mp;

        while(temp){
            mp[temp->val]++;
            temp = temp->next;
        }

        temp = head;
        while(temp && head){
            if(mp[temp->val] > 1){
                if(prev == NULL){
                    head = head->next;
                    temp = head;
                }else{
                    prev->next = temp->next;
                    temp = temp->next;
                }
            }else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};

int main(){
    ListNode* head = new ListNode();
    newNode(head, 1);
    newNode(head, 1);
    newNode(head, 1);
    newNode(head, 2);
    newNode(head, 3);

    Solution s;
    ListNode* res = s.deleteDuplicates(head);
    while(res){
        cout<<res->val<<endl;
        res = res->next;
    }
}