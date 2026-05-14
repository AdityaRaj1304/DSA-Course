#include<iostream>
#include<string>
#include<vector>
using namespace std ;
class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>pal;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]>='a'&&s[i]<='z'){
                pal.push_back(s[i]);
            }
             if(s[i]>='A'&&s[i]<='Z'){
                pal.push_back(s[i]-'A'+'a');
            }
            if(s[i]>='0'&&s[i]<='9'){
                pal.push_back(s[i]);
            }
        }
        int st = 0 , end = pal.size()-1;
        while(st<end){
            if(pal[st++]!=pal[end--]){
                cout << "Invalid Palindrome\n";
                return false;
            }
        }
        return true ;
    }
};

