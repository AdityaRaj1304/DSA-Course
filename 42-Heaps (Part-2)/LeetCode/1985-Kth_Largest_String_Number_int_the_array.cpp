#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Compare{
        bool operator () (const string& a , const string& b) const{
            if(a.size()!=b.size()){
                return a.size()>b.size();
            }
            return a>b;
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,Compare>pq;
        for(string & num:nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};



class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k = 0;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int& num:nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};