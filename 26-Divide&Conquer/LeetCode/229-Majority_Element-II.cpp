#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int count1 = 0 , count2 = 0 , cand1 = 0 , cand2 = 0;
        for(int i:nums){//Finding Candidates
            if(i==cand1){
                count1++;
            }
            else if(i==cand2){
                count2++;
            }
            else if(count1==0){
                cand1=i;
                count1++;
            }
            else if(count2==0){
                cand2=i;
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        // Verification Stage
        count1=0,count2=0;
        for(int i: nums){
            if(i==cand1){
                count1++;
            }else if(i==cand2){
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