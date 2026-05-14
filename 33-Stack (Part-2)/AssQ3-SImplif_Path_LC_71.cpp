#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s;
        string temp ="";
        for(int i = 0 ;i<=path.size();i++){
            if(i==path.size() || path[i] == '/'){
                if(temp == "" || temp == "."){
                    //ignore
                }else if(temp == ".."){
                    if(!s.empty()){
                        s.pop();
                    }
                }else{
                    s.push(temp);
                }
                temp="";
            }else{
                temp+=path[i];
            }
        }
        if(s.empty()){
            return "/";
        }
        string ans ="";
        while(!s.empty()){
            ans="/" + s.top() + ans;
            s.pop();
        }
        return ans;
    }
};