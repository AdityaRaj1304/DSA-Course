#include<bits/stdc++.h>
using namespace std;

class Queue_front{
    stack<int>s1;
    stack<int>s2;
public:
    void push(int data) { //O(N)
        //Step-1 => s1->s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        //Step-2 => push data in s1 
        s1.push(data);
        //Step-3 => s2->s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){ //O(1)
        if(s1.empty()){
            return;
        }
        s1.pop();    
    }

    int front(){  //O(1)
        if(s1.empty()){
            return -1;
        }
        return s1.top();
    }

    bool empty(){ //O(1)
        return s1.empty();
    }
};


class Queue_rear{
    stack<int>s1;
    stack<int>s2;
public:
    void push(int data){ //O(1)
        s1.push(data);
    }

    void pop(){  // O(n)
        if(empty()){
            return;
        }
        // Step-1 => Move all elements of s1 to s2 (except the last one)
        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        //Step-2 => Pop the last element of s1
        s1.pop();
        //Step-3 => Push all elements of s2 to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int front(){  //O(N)
        int front_element = 0;
        if(empty()){
            return -1;
        }
        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        front_element = s1.top();
        // s2.push(s1.top());
        // s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return front_element;
    }

    bool empty(){
        return s1.empty();
    }
};


int main(){
    Queue_rear q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout << q.front() << endl; 
        q.pop();
    }
    return 0;
}