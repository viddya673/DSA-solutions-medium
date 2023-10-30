#include <bits/stdc++.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) : data(x), next(NULL), bottom(NULL) {}
};

using namespace std;

void printList(Node* Node) {
    while (Node != NULL) {
        cout << Node->data << " ";
        Node = Node->bottom;
    }
}

Node* mergeSortedLists(Node* root1, Node* root2) {
    Node* dummy = new Node(0);
    Node* ptr = dummy;
    Node* temp1 = root1;
    Node* temp2 = root2;

    while (temp1 && temp2) {
        if (temp1->data < temp2->data) {
            ptr->bottom = temp1;
            temp1 = temp1->bottom;
        } else {
            ptr->bottom = temp2;
            temp2 = temp2->bottom;
        }
        ptr = ptr->bottom;
    }

    if (temp1) {
        ptr->bottom = temp1;
    }
    if (temp2) {
        ptr->bottom = temp2;
    }
    return dummy->bottom;
}

Node* flatten(Node* root) {
    if (!root || !root->next)
        return root;

    Node* temp = root;
    while (temp->next) {
        Node* nextNode = temp->next;
        root = mergeSortedLists(root, nextNode);
        temp = nextNode;
    }
    return root;
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node* temp = NULL;
        struct Node* head = NULL;
        struct Node* pre = NULL;
        struct Node* tempB = NULL;
        struct Node* preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i] - 1;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            } else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {
                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                } else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }

        Node* root = flatten(head);
        printList(root);
        cout << endl;
    }
    return 0;
}
