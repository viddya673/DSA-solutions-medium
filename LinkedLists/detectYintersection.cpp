#include <iostream>
#include <map>
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

/* Approach 1 */
int findLength (Node* head){
    int len = 0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}
Node* findIntersection1(Node *firstHead, Node *secondHead)
{
    int len1 = findLength(firstHead);
    int len2 = findLength(secondHead);
    int diff = abs(len1-len2);

    if(len1>len2){
        while (diff) {
          firstHead = firstHead->next;
          diff--;
        }
    }
    else if(len2>len1){
        while (diff) {
          secondHead = secondHead->next;
          diff--;
        }
    }
    while(firstHead!=NULL && secondHead!=NULL){
        if(firstHead==secondHead)
            return firstHead;
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    return NULL;
}

/* Approach 2 */
Node* findIntersection2(Node *firstHead, Node *secondHead)
{
    Node* d1 = firstHead;
    Node* d2 = secondHead;

    while(d1 != d2){
        d1 = (d1==NULL) ? secondHead : d1->next;
        d2 = (d2==NULL) ? firstHead : d2->next;
    }

    return d1;
}
/* Approach 3: Use a hash set*/

int main(){
    Node* head = new Node();
    newNode(head, 1);
    newNode(head, 2);
    newNode(head, 3);
    newNode(head, 4);
    newNode(head, 5);

    Node* head1 = head;
    head = head->next->next;
    Node* headSec = new Node();
    newNode(headSec,13);
    Node* head2 = headSec;
    headSec->next = head;

    cout<<findIntersection1(head1, head2)->val<<endl;
    cout<<findIntersection2(head1, head2)->val<<endl;
}