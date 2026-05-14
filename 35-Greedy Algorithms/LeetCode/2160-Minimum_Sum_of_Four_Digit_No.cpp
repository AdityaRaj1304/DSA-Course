#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        int ans = 0 ;
        vector<int>digits;
        while(num){
            digits.push_back(num%10);
            num/=10;
        }
        sort(digits.begin(),digits.end());
        ans += (digits[0]*10+digits[3])+(digits[1]*10+digits[2]);
        return ans;
    }
};