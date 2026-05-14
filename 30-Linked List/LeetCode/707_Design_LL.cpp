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
class MyLinkedList {
public:
    Node* head ;
    Node* tail;
    MyLinkedList() {
        head = NULL;
        tail=NULL;
    }
    
    int get(int index) {
        Node *temp = head;
        int idx = 0;
        for(int i = 0 ;i<index&& temp;i++){
            temp=temp->next;
        }
        if(temp){
            return temp->data;
        }else{
            return -1;
        }
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head = newNode;
        }
    }
    
    void addAtTail(int val) {
        Node *newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail = newNode;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return;
        }
        Node *temp = head;
        for(int i = 0 ; i< index-1 && temp;i++){
            temp=temp->next;
        }
        if(!temp){
            return;
        }
        Node* newNode = new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        if(newNode->next == NULL)
        tail = newNode;
    }
    
void deleteAtIndex(int index) {
    if(!head) return;

    if(index == 0){
        Node* del = head;
        head = head->next;
        delete del;
        if(!head) tail = NULL;
        return;
    }

    Node *temp = head;
    for(int i = 0; temp && i < index-1; i++){
        temp = temp->next;
    }

    if(!temp || !temp->next) return;

    Node* toDel = temp->next;
    temp->next = toDel->next;

    if(toDel == tail)
        tail = temp;

    delete toDel;
}
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */