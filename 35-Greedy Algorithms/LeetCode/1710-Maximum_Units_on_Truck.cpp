#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans =0;
        sort(boxTypes.begin(),boxTypes.end(),[](auto &a , auto&b){
            return a[1]>b[1];
        });
        for(int i = 0 ;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=truckSize){
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
                truckSize-=boxTypes[i][0];
            }else{
                ans+=truckSize*boxTypes[i][1];
                break;
            }
        }
        return ans;
    }
};