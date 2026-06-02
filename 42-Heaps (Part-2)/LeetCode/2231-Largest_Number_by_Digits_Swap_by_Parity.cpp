#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int>odd,even;
        string s = to_string(num);
        int n = s.size();
        for(char ch:s ){
            if((ch-'0')%2==0){
                even.push(ch-'0');
            }else{
                odd.push(ch-'0');
            }
        }
        string ans(n,' ');
        int idx =0;
        for(char ch:s ){
            if((ch-'0')%2==0){
                ans[idx++]=even.top()+'0';
                even.pop();
            }else{
                ans[idx++]=odd.top()+'0';
                odd.pop();
            }
        }
        return stoi(ans);
    }
};