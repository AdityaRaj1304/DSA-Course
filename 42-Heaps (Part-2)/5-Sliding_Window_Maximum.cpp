#include<bits/stdc++.h>
using namespace std;

void slidingWindowHeap(vector<int>&arr,int K){
    priority_queue<pair<int,int>>pq;

    //1st Window
    for(int i = 0;i<K;i++){
        pq.push({arr[i],i});
    }
    cout << "Output: " << pq.top().first << " ";
    for(int i =K;i<arr.size();i++){
        while(!pq.empty() && pq.top().second<=(i-K)){ // Outside Window Elements
            pq.pop();
        }
        pq.push({arr[i],i});
        cout << pq.top().first << " ";
    }
    cout << endl;
}


void slidingWindowDQ(vector<int>&arr, int K){
    deque<int>dq;
    cout << "Output: ";
    for(int i = 0;i<arr.size();i++){
        while(!dq.empty() && arr[dq.back()]<=arr[i]){ //Smaller Elements Present At Back of DQ to be removed
            dq.pop_back();
        }
        while(!dq.empty() && dq.front()<=(i-K)){//Out Of Window Elements Present at the Front of the DQ
            dq.pop_front();
        }
        dq.push_back(i);
        if(i>=K-1){
            cout << arr[dq.front()] << " ";
        }
    }
    cout << endl;
}


int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    vector<int> test = {1,3,-1,-3,5,3,6,7};
    int K = 3;
    slidingWindowHeap(arr,K);
    slidingWindowHeap(test,K);
    slidingWindowDQ(arr,K);
    slidingWindowDQ(test,K);
    return 0;
}