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

Node* deleteNafterM(Node* head , int m , int n){
    Node* left = head;
    while(left){
    for(int i = 1 ; i<m&&left;i++){
        left=left->next;
    }
    if(!left){
        return head;
    }
    Node* right = left->next;
    for(int i = 0 ; i<n&&right;i++){
        Node* toDel = right;
        right=right->next;
        delete toDel;
    }
    left->next=right;
    left=right;
}
    return head;
}


int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    int m = 2 , n=2;
    ll.printList();
    deleteNafterM(ll.head,m,n);
    ll.printList();
    return 0;
}