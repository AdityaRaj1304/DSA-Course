#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int ans = 0;
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        int sum = 0;
        vector<int>temp;
        for(int i = n-1;i>=0;i--){
            sum+=satisfaction[i];
            if(sum>0){
                temp.push_back(satisfaction[i]);
            }else{
                break;
            }
        }
        int size = temp.size();
        for(int i = size-1;i>=0;i--){
            ans+=temp[i]*(size-i);
        }
        return ans;
    }
};