#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int length = n ;
        for(int i = n-1 ;i>=0;i--){
            char ch = num[i];
            if((ch - '0') %2 !=0){
                break;
            }else{
                length--;
            }
        }
        return num.substr(0,length);
    }
};