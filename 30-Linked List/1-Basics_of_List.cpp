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
    ~Node(){
        if(next!=NULL){
            delete next;
            next = NULL;
        }
    }
};
class List{
    Node *head;
    Node *tail;
    public:
    List(){
        head=NULL;
        tail=NULL;
    }
    ~List(){
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }

    // Push Front
    void push_front(int val){
        Node *newNode = new Node(val);//dynamic
        // Node *newNode(val); // static
        if(head == NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
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

    // Insert in Middle
    void insert(int val , int pos){
        Node *newNode = new Node(val);
        Node *temp =head;
        for(int i = 0 ; i<pos-1;i++){
            if(temp==NULL){
                cout << "Invalid Position";
                return;
            }
            temp=temp->next;
        }
        //temp is now at pos-1 i.e. prev/left
        newNode->next=temp->next;
        temp->next=newNode;
    }

    //Pop Front
    void pop_front(){
        if(head==NULL){
            cout << "Empty LL";
            return;
        }
        Node *temp = head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    //Pop Back
    void pop_back(){
        Node *temp =head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL; //temp = tail's prev 
        delete tail;
        tail=temp;
    }


    //Iterative Search in LL
    int searchItr(int key){
        Node *temp=head;
        int idx = 0;
        while(temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;
    }

    //Recursive Search in LL
    int helper(Node *head, int key){
        if(head==NULL){
            return -1;
        }
        if(head->data==key){
            return 0;
        }
        int idx = helper(head->next,key);
        if(idx==-1){
            return -1;
        }
        return idx+1;
    }
    int search_rec(int key){
        return helper(head,key);
    }

    //Reverse Linked List
    void reverse(){
        Node *curr =head;
        Node *prev =NULL;
        tail=head;
        while(curr!=NULL){
            Node *next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }

    //Find & Remove Nth node from the End
    int getSize(){
        int sz=0;
        Node *temp =head;
        while(temp!=NULL){
            temp=temp->next;
            sz++;
        }
        return sz;
    }
    void removeNth(int n){
        Node *prev =head;
        int size = getSize();
        for(int i = 1 ;i<(size-n);i++){
            prev=prev->next;
        }
        Node *toDel = prev->next;
        cout << "going to delete " << toDel->data << endl;
        prev->next=prev->next->next;
        delete toDel;

    }
    //Print List
    void printList(){
        Node *temp =head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp=temp->next;
        }
        cout<<"NULL" ;
    }
};

int main(){
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(5);
    ll.push_back(6);
    ll.printList();
    cout <<"\n";
    ll.reverse();
    ll.printList();
    cout << endl;
    ll.insert(4,3);
    ll.pop_back();
    ll.pop_front();
    ll.printList();
    cout << "\n";
    cout << ll.searchItr(4)<<endl;
    cout << "\n";
    ll.removeNth(3);
    ll.printList();
}

