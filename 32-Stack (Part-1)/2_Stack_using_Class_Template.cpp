#include<bits/stdc++.h>
using namespace std;

template<class T> // Created A Template T which can have any datatype 

class Stack{
    vector<T>vec;
    public:
    void push(T val){
        vec.push_back(val);
    }
    void pop(){
        if(isEmpty()){
            cout << "Empty Stack";
            return ;
        }
        vec.pop_back();
    }
    T top(){
        // if(isEmpty()){
        //     cout << "Empty Stack";
        //     return -1;
        // }
        int lastIdx=vec.size()-1;
        cout << vec[lastIdx] << endl;
        return vec[lastIdx];
    }
    bool isEmpty(){
        return vec.size()==0;
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