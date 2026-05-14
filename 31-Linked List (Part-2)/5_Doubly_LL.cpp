#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data=val;
        prev=next=NULL;
    }
};
class DoublyList{
    public:
    Node* head ;
    Node* tail;
    DoublyList(){
        head=tail=NULL;
    }
    void push_front(int val){
        Node* newNode =new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }
    void pop_front(){
        if(!head){
            return;
        }
        Node* temp = head;
        head=head->next;
        if(head){
            head->prev=NULL;
        }else{
            tail=NULL; //list becomes empty
        }
        temp->next=NULL;
        delete temp;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            Node* temp = head;
            while(temp->next){
                temp=temp->next;
            }
            //temp is now at last node
            temp->next=newNode;
            newNode->prev=temp;
            tail=newNode;
        }
    }
    void pop_back(){
    if(!tail) return;

    Node* temp = tail;

    if(head == tail){  // only 1 node
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    delete temp;
}

};