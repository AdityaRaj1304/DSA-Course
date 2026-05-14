#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data ;
    Node *next;
    Node(int val){
        data = val;
        next=NULL;
    }
};

class List{
    public:
    Node *head;
    Node *tail;
    List(){
        head=NULL;
        tail=NULL;
    }

    //Push Back
    void push_back(int val){
        Node *newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void printList(){
        Node *temp =head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout<<"NULL" << endl;
    }
};

// Function to get size of list
int getSize(Node* head) {
    int sz = 0;
    while (head) {
        sz++;
        head = head->next;
    }
    return sz;
}

// Intersection Function
Node* getIntersectionNode(Node* headA, Node* headB) {
    int m = getSize(headA);
    int n = getSize(headB);

    Node* ptr1 = headA;
    Node* ptr2 = headB;

    // Align pointers
    while (m > n) {
        ptr1 = ptr1->next;
        m--;
    }
    while (n > m) {
        ptr2 = ptr2->next;
        n--;
    }

    // Move together
    while (ptr1 && ptr2) {
        if (ptr1 == ptr2) return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    List A, B;

    // Create List A: 1->2->3
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);

    // Create common part: 8->10
    Node* common = new Node(8);
    common->next = new Node(10);

    // Attach common part to A
    A.tail->next = common;
    A.tail = common->next;

    // Create List B: 4
    B.push_back(4);

    // Attach same common nodes to B (INTERSECTION)
    B.tail->next = common;
    B.tail = common->next;

    cout << "List A: ";
    A.printList();

    cout << "List B: ";
    B.printList();

    Node* intersection = getIntersectionNode(A.head, B.head);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection found\n";

    return 0;
}
