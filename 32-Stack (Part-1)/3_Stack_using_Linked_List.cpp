#include<bits/stdc++.h>
using namespace std;

// Method 1 (Using STL List)
// template<class T>
// class Stack{
//     list<T>ll;
// public:
//     void push(T val){
//         ll.push_front(val);
//     }
//     void pop(){
//         ll.pop_front();
//     }
//     T top(){
//         cout << ll.front() << endl;
//         return ll.front();
//     }
//     bool isEmpty(){
//         return ll.size()==0;
//     }
// };


// Method 2 (Without using inbuilt List)

template<class T>
class Node{
public:
    T data;
    Node<T>* next;
    Node(T val){
        data=val;
        next=NULL;
    }
};
template<class T>
class Stack{
public:
    Node<T>* head;
    Stack(){
        head = NULL;
    }
    void push(T val){
        //push->front
        Node<T>*newNode = new Node<T>(val);
        if(head==NULL){
            head=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }
    void pop(){
        //push->front
        if(head==NULL){
            cout << "Empty Stack";
            return;
        }
        Node<T>*temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    T top(){
        cout << head->data << endl;
        return head->data;
    }
    bool isEmpty(){
        return head==NULL;
    }
};
int main(){
    Stack <string>s;
    s.push("Hello");
    s.push("Aditya");
    s.top();
    s.pop();
    s.top();
    s.isEmpty();
}