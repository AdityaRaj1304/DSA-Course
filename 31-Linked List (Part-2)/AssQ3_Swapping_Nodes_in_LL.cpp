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

Node* swapping_nodes(Node* head,int x , int y){
    if(x==y){
        return head;
    }
    Node* currX = head , *currY=head;
    Node* prevX = NULL , *prevY=NULL;
    //Find X and its prev node
    while(currX && currX->data!=x){
        prevX=currX;
        currX=currX->next;
    }
    //Find Y and its prev node
    while(currY && currY->data!=y){
        prevY=currY;
        currY=currY->next;
    }
        // If either not found
        if (!currX || !currY) return head;

        // Fix previous pointers
        if (prevX)
            prevX->next = currY;
        else
            head = currY;  // x was head

        if (prevY)
            prevY->next = currX;
        else
            head = currX;  // y was head

        // Swap next pointers
        // Node* temp = currX->next;
        // currX->next = currY->next;
        // currY->next = temp;
        swap(currX->next,currY->next);
        return head;
}
int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.printList();
    int x = 2 , y=4;
    swapping_nodes(ll.head,x,y);
    ll.printList();
}