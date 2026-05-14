#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        string ans ;
        stack<int>num;
        stack<string>st;
        int n = 0;
        for(char ch : s){
            if(ch>='0' && ch <='9'){
                n = n*10 + (ch -'0');
            }else if(ch == '['){
                num.push(n);
                n=0;
                st.push(ans);
                ans="";
            }else if(ch == ']'){
                int k = num.top();
                num.pop();
                string temp = ans;
                ans = st.top();
                st.pop();
                for(int i = 0 ;i<k;i++){
                    ans+=temp;
                }
            }else{
                ans+=ch;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    string s1 = "3[a]2[bc]";
    string s2 = "2[abc]3[cd]ef";
    cout << s.decodeString(s1)<< endl;
    cout << s.decodeString(s2);
    return 0;
}