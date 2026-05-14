#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int left = 0 , right = 0;
        int ans= 0;
        for(char ch:s){
            if(ch == 'L'){
                left++;
            }else{
                right++;
            }
            if(left==right){
                ans++;
                left=0,right=0;
            }
        }
        return ans;
    }
};