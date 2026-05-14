#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class List{
    public:
    Node*head;
    Node*tail;
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
};

    //Print List
    void printList(Node* head){
        Node *temp =head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout<<"NULL" << endl;
    }


// Code for Zig-Zag LL 

//Step 1: Split the list into two halves
Node* splitAtmid(Node* head){
    Node* slow = head , *fast= head;
    Node* prev = NULL;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev!=NULL){
        prev->next=NULL;
    }
    return slow;
}

//Step 2: Reverse the Second Part of the List so that we can traverse the list in backward direction
Node* reverse(Node* head){
    Node*curr=head;
    Node*prev=NULL;
    while(curr!=NULL){
        Node* next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;//prev is the head of reverse list
}

//Step 3: Main Function 
Node* zizZagLL(Node *head){
    if(!head || !head->next){
        return head;
    }
    Node* rightHead= splitAtmid(head);
    Node* rightHeadrev = reverse(rightHead);

    //alternate merging 
    Node* left =head;
    Node* right = rightHeadrev;
    Node* tail = right;
    while(left!=NULL && right!=NULL){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;
        left->next=right;
        right->next=nextLeft;
        tail = right;
        left=nextLeft;
        right = nextRight;
    }
    if(right!=NULL){
        tail->next=right;
    }
    return head;
}

// //Step 3: Main Function(Without Tail)
// Node* zizZagLL2(Node *head){
//     if(!head || !head->next){
//         return head;
//     }
//     Node* rightHead= splitAtmid(head);
//     Node* rightHeadrev = reverse(rightHead);
//     //alternate merging 
//     Node* left =head;
//     Node* right = rightHeadrev;
//     while(right){
//         Node* nextLeft = left->next;
//         Node* nextRight = right->next;
//         left->next=right;
//         right->next=nextLeft;
//         left=nextLeft;
//         right = nextRight;
//     }
//     return head;
// }


int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    printList(ll.head);
    zizZagLL(ll.head);
    printList(ll.head);
    return 0;
}