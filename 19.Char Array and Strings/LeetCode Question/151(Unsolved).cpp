#include<iostream>
#include<string>
#include<vector>
using namespace std ;
class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        string temp = "";
        for(char ch : s){
            if(ch == ' '){
                if(!temp.empty()){
                    words.push_back(temp);
                    temp = "";
                }
            }else{
                temp+=ch;
            }
        }
        if(!temp.empty()){
            words.push_back(temp);
        }
        string ans ;
        for(int i = words.size()-1;i>0;i--){
            ans+= words[i] + " ";
        }
        ans += words[0];
        return ans;
    }
};