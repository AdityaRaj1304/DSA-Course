#include<bits/stdc++.h>
using namespace std;

queue<int> reverse(queue<int>&q,int k){
    int n = q.size();
    stack<int>s;
    for(int i =0 ;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i = 0 ;i<n-k;i++){
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main(){
    queue<int>q;
    for(int i = 1 ;i<=5;i++){
        q.push(i);
    }
    reverse(q,3);
    for(int i = 1 ;i<=5;i++){
        cout << q.front() << " ";
        q.pop();
    }
}