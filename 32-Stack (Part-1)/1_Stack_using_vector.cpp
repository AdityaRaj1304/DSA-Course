#include<bits/stdc++.h>
using namespace std;

class Stack{
    vector<int>vec;
    public:
    void push(int val){
        vec.push_back(val);
    }
    void pop(){
        if(isEmpty()){
            cout << "Empty Stack";
            return ;
        }
        vec.pop_back();
    }
    int top(){
        if(isEmpty()){
            cout << "Empty Stack";
            return -1;
        }
        int lastIdx=vec.size()-1;
        cout << vec[lastIdx] << endl;
        return vec[lastIdx];
    }
    bool isEmpty(){
        return vec.size()==0;
    }
};

int main(){
    Stack s;
    s.push(5);
    s.push(4);
    s.top();
    s.pop();
    s.top();
    s.isEmpty();
}