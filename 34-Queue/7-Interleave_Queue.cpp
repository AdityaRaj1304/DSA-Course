#include<bits/stdc++.h>
using namespace std;

void interleave(queue<int>&org){
    int n = org.size();
    queue<int>temp;
    for(int i = 0; i<n/2;i++){
        temp.push(org.front());
        org.pop();
    }
    while(!temp.empty()){
        org.push(temp.front());
        temp.pop();
        org.push(org.front());
        org.pop();
    }
}

int main(){
    queue<int>q;
    for(int i = 1 ; i<=10;i++){
        q.push(i);
    }
    interleave(q);
    while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
}
    return 0;
}