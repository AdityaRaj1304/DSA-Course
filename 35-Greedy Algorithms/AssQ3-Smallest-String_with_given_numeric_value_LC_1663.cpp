#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        while(k){
            if(k>=(25+n)){
                ans+=('a'+25);
                k-=26;
                n--;
            }else if(k>n){
                ans+=('a'+(k-n));
                k-=(k-n+1);
                n--;
            }else{
                ans+='a';
                n--;
                k--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

string getSmallestString(int n, int k) { // Class Approach 
       string ans;
       while(n!=0){
           int ch = k-(n-1)*26;
           if(ch<=0){
               ans.push_back('a');
               k--;
               n--;
           }
           else{
               ans.push_back(ch+'a'-1);
               n--;
               k -= (ch);
           }
       }
       return ans;
   }


class Solution {  // ChatGPT Approach
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');   // start with all 'a'
        k -= n;               // remaining value

        for(int i = n - 1; i >= 0 && k > 0; i--){
            int add = min(25, k);
            ans[i] += add;
            k -= add;
        }

        return ans;
    }
};