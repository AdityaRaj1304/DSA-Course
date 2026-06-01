#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        vector<string>ans(n,"");
        for(int i = 0;i<n;i++){
            pq.push({score[i],i});
        }
        int rank =0;
        while(!pq.empty()){
            rank++;
            if(rank==1){
                ans[pq.top().second]="Gold Medal";
                pq.pop();
            }else if(rank ==2){
                ans[pq.top().second]="Silver Medal";
                pq.pop();
            }else if(rank ==3){
                ans[pq.top().second]="Bronze Medal";
                pq.pop();
            }else{
                ans[pq.top().second]=to_string(rank);
                pq.pop();
            }
        }
        return ans;
    }
};