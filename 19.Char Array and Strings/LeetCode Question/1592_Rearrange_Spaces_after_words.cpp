#include<iostream>
#include<string>
#include<vector>
using namespace std ;
class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        int spaces = 0;
        string word = "";

        for(char ch : text){
            if(ch == ' '){
                spaces++;
                if(!word.empty()){
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += ch;
            }
        }
        if(!word.empty()) {
            words.push_back(word);
        }

        int gaps = 0, extra = 0;
        if(words.size() == 1) {
            extra = spaces;
        } else {
            gaps = spaces / (words.size() - 1);
            extra = spaces % (words.size() - 1);
        }

        string ans;
        for(int i = 0; i < words.size(); i++){
            ans += words[i];

            if(i == words.size() - 1){
                ans += string(extra, ' ');
            } else {
                ans += string(gaps, ' ');
            }
        }

        return ans;
    }
};