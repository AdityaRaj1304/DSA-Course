#include<bits/stdc++.h>
using namespace std;

struct comparePair{
    bool operator () (pair<string,int>&p1 , pair<string,int>&p2){
        return p1.second > p2.second ;  // Max Heap(<) , Min Heap(>)
    }
};

int main(){
    //priority_queue<pair<string,int>>pq; //Max Heap (Default)
    priority_queue<pair<string,int>,vector<pair<string,int>>,comparePair>pq;
    pq.push(make_pair("Aditya",1));
    pq.push(make_pair("Pratham",2));
    pq.push(make_pair("Abhisekh",3));

    while(!pq.empty()){
        cout << pq.top().first << "," << pq.top().second << endl; 
        pq.pop();
    }
    
    
    return 0;
}