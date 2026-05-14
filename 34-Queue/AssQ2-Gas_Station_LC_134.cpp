#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr = 0 , total = 0;
        int ans = 0;
        int n = gas.size();
        for(int i = 0 ; i<n;i++){
            curr+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(curr<0){
                ans=i+1;
                curr=0;
            }
        }
        if(total<0){
            return -1;
        }else{
            return ans;
        }
    }
};
