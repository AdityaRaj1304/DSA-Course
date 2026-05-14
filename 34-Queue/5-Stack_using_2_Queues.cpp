#include<bits/stdc++.h>
using namespace std;

class Stack_front{ // Method -1 => Front of Queue as Top of Stack
    queue<int>q1 ;
    queue<int>q2 ;
public:
    void push(int data){ //O(N) 
        //Step-1 => q1->q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(){
        if(q1.empty()){
            return;
        }
        q1.pop();
    }

    int top(){
        if(q1.empty()){
            return -1;
        }
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};


class Stack_rear{ // Method -2 => Rear of Queue as Top of Stack
    queue<int>q1 ;
    queue<int>q2 ;
public:
    void push(int data){ //O(N) 
        q1.push(data);
    }
    void pop(){
        if(q1.empty()){
            return;
        }
        //Step-1 => q1->q2
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        //Step-2 => Pop the last element of q1
        q1.pop();
        //Step-3 => Swap both the queues
        swap(q1,q2);
    }

    int top(){
        if(q1.empty()){
            return -1;
        }
        int top_element=0;
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        top_element=q1.front();
        q2.push(q1.front());
        q1.pop();
        swap(q1,q2);
        return top_element;
    }

    bool empty(){
        return q1.empty();
    }
};


int main(){
    Stack_front s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}