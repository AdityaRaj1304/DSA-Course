#include<bits/stdc++.h>
using namespace std;


//Hash Map =TC = O(n) & SC = O(n) {Worst}
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> ans;
        int n = nums.size();
        for(int num : nums){
            freq[num]++;
        }
        for(auto it : freq){
            if(it.second > n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};


//Boyer-Moore Voting
void majElement(vector<int>&nums){
    int candidate1 = 0 , candidate2 = 1;
    int count1 = 0 , count2 = 0;
    for(int num:nums){
        if(num==candidate1){
            count1++;
        }else if(num == candidate2){
            count2++;
        }else if(candidate1 == 0){
            candidate1=num;
            count1=1;
        }else if(candidate2 == 0){
            candidate2 = num;
            count2=0;
        }else{
            count1--;
            count2--;
        }
    }
}


