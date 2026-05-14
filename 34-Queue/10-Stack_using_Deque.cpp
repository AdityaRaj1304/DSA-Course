#include<iostream>
#include<deque>
using namespace std;

class Stack_front{
    deque<int>deq;
public:
    void push(int data){
        deq.push_front(data);
    }

    void pop(){
        deq.pop_front();
    }

    int top(){
        return deq.front();
    }

    bool empty(){
        return deq.empty();
    }
};

class Stack_rear{
    deque<int>deq;
public:
    void push(int data){
        deq.push_back(data);
    }

    void pop(){
        deq.pop_back();
    }

    int top(){
        return deq.back();
    }

    bool empty(){
        return deq.empty();
    }
};

int main(){
    Stack_front s1;
    Stack_rear s2;
    for(int i = 1 ;i<=5;i++){
        s1.push(i);
    }
    for(int i = 1 ;i<=5;i++){
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
        for(int i = 1 ;i<=5;i++){
        s2.push(i);
    }
    for(int i = 1 ;i<=5;i++){
        cout << s2.top() << " ";
        s2.pop();
    }
    return 0;
}