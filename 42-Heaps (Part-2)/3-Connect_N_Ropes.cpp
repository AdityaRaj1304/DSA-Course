#include<bits/stdc++.h>
using namespace std;

void connectNRopes(vector<int>&ropes){
    priority_queue<int,vector<int>,greater<int>>pq(ropes.begin(),ropes.end());
    int cost = 0;
    while(pq.size()>1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        cost+= x+y;
        pq.push(x+y);
    }
    cout << "Min Cost: " << cost ; 
}

int main(){
    vector<int>lengths={4,3,2,6};
    connectNRopes(lengths);
    return 0;
}