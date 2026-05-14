#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0 , end = height.size()-1;
        int currwater = 0 , length = 0 , width = 0 , maxwater = 0;
        while(st<end){
            width = min(height[st],height[end]);
            length= end - st ;
            currwater = length * width ;
            maxwater = max(currwater,maxwater);
            if(height[st]>height[end]){
                end--;
            }else{
                st++;
            }
        }
        return maxwater;
    }
};