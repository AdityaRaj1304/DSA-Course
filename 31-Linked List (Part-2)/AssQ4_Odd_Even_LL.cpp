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


// Odd Even Function
Node* oddEven(Node* head) {
    if (!head) return head;

    Node *evenHead = NULL, *evenTail = NULL;
    Node *oddHead = NULL, *oddTail = NULL;

    Node* curr = head;

    while (curr) {
        Node* nextNode = curr->next;
        curr->next = NULL;

        if (curr->data % 2 == 0) {   // EVEN
            if (!evenHead) {
                evenHead = evenTail = curr;
            }else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {                     // ODD
            if (!oddHead) oddHead = oddTail = curr;
            else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }

        curr = nextNode;
    }

    // If no even numbers
    if (!evenHead) return oddHead;

    // If no odd numbers
    if (!oddHead) return evenHead;

    // Connect lists
    evenTail->next = oddHead;

    return evenHead;  
}




int main(){
    List ll;
    // ll.push_back(8);
    // ll.push_back(12);
    // ll.push_back(10);
    // ll.push_back(5);
    // ll.push_back(4);
    // ll.push_back(1);
    // ll.push_back(6);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();
    ll.head=oddEven(ll.head);
    ll.printList();
}