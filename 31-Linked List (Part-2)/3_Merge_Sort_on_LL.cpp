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
};

    //MergeSort on LL

    //Step 1: Split at Mid (Split the ll into two halves - left & right)
    Node* splitAtMid(Node*head){
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL){
            prev->next=NULL;
        }
        return slow; // slow = rightHead
    }

    //Step 2: Merge Stop (To Merge list) - Extra Space 
    // Node* merge(Node* left , Node* right){
    //     List ans;
    //     Node* i = left;
    //     Node* j = right;
    //     while(i!=NULL && j!=NULL){
    //         if(i->data<=j->data){
    //             ans.push_back(i->data);
    //             i=i->next;
    //         }else{
    //             ans.push_back(j->data);
    //             j=j->next;
    //         }
    //     }
    //     while(i!=NULL){
    //         ans.push_back(i->data);
    //         i=i->next;
    //     }
    //     while(j!=NULL){
    //         ans.push_back(j->data);
    //         j=j->next;
    //     }
    //     return ans.head;
    // } 


    //Step 2: Merge Stop (To Merge list) - Without Extra Space 
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* head = NULL;
    Node* tail = NULL;

    // Decide first node
    if (left->data <= right->data) {
        head = tail = left;
        left = left->next;
    } else {
        head = tail = right;
        right = right->next;
    }

    // Merge remaining
    while (left && right) {
        if (left->data <= right->data) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    // Attach leftover
    tail->next = (left) ? left : right;

    return head;
}


    // Step3: MergeSort
    Node* mergeSort(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* rightHead= splitAtMid(head);
        
        Node* left=mergeSort(head);//Left Head
        Node* right=mergeSort(rightHead);//Right Head

        return merge(left,right);//head of sorted list
    }

    //Print List
    void printList(Node* head){
        Node *temp =head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout<<"NULL" ;
    }


int main(){
    List ll;
    ll.push_back(4);
    ll.push_back(7);
    ll.push_back(11);
    ll.push_back(2);
    ll.push_back(5);
    ll.push_back(1);
    printList(ll.head);
    cout<<"\n";
    ll.head=mergeSort(ll.head);
    printList(ll.head);
    return 0;
}