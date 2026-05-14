#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(2,0);
        vector<int> count(n+1,0);
        for(int i = 0 ; i <=n ; i++){
            count[nums[i]]++;
        }
        for(int i = 1 ; i <=n ;i++){
            if(count[i]==2){
                answer[0]=i;
            }
            if(count[i]==0){
                answer[1]=i;
            }
        }
        return answer;
    }
};
