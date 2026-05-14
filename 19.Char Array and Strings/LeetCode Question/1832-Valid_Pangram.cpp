#include<iostream>
#include<string>
#include<vector>
using namespace std ;
class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length()<26){
            return false ;
        }
        int count[26]={0};
        for(int i = 0 ; i < sentence.length() ; i++){
            int index = sentence[i]-'a';
            count[index]++;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(count[i]==0){
                return false ;
            }
        }
        return true ;
    }
};