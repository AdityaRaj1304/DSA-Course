#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand1=0,cand2=0,count1=0,count2=0;
        vector<int>ans;
        for(int i :nums){
            if(i==cand1){
                count1++;
            }
            else if(i==cand2){
                count2++;
            }
            else if (count1==0){
                cand1=i;
            }
            else if(count2==0){
                cand2=i;
            }else{
                count1--;
                count2--;
            }
        }
        count1=0,count2=0;
        for(int i:nums){
            if(i==cand1){
                count1++;
            }
            else if(i== cand2){
                count2++;
            }
        }
        if(count1>n/3){
            ans.push_back(cand1);
        }
        if(count2>n/3){
            ans.push_back(cand2);
        }
        return ans;
    }
};