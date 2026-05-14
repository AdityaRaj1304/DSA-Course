#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st = 0 , end = numbers.size()-1;
        vector<int>answer;
        int currsum = 0;
        while(st<end){
            currsum=numbers[st]+numbers[end];
            if(currsum==target){
                answer.push_back(st+1);
                answer.push_back(end+1);
                return answer;
            }else if(currsum > target){
                end--;
            }else{
                st++;
            }
        }
        return answer;
    }
};