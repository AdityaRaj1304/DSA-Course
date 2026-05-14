#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product1 = 1;
        int product2 = 1 ;
        int count = 0;
        int n = nums.size();
        vector<int>answer(n,1);
        for(int i = 0 ; i < n ; i++){
            product1 *= nums[i];
            if(nums[i]==0){
                count++;
            }
        }
        for(int i = 0 ; i < n; i++){
            if(nums[i]!=0){
                product2 *= nums[i];
            }
        }
        for(int i = 0 ; i < n ;i++){
            if(count==0){
                answer[i]=product1/nums[i];
            }else{
                if(nums[i]!=0){
                    answer[i]=0;
                }else{
                    answer[i]=product2;
                }
            }
        }
        return answer;
    }
};