#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int c1 = 0 ,c2 =0 ;
        int ans = 0;
        string temp = s;
        if(s[0]='1'){
            temp[0]='0';
        }else{
            temp[0]='1';
        }
        for(int i = 1 ;i<s.size();i++){
            if(s[i]==s[i-1]){
                c1++;
                if(s[i]=='0'){
                    s[i]='1';
                }else{
                    s[i]='0';
                }
            }
            if(temp[i]==temp[i-1]){
                c2++;
                if(temp[i]=='0'){
                    temp[i]='1';
                }else{
                    temp[i]='0';
                }
            }
        }
        return min(c1,c2);
    }
};