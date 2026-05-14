#include<iostream>
#include<string>
using namespace std ;
class Solution {
public:
    string reverseVowels(string s) {/*Wrong Approach becuase in C++ This does not check if s[st] equals any vowel 
        — instead, 'e', 'i', etc., are always evaluated as true (since they’re non-zero characters), making your 
        conditions always true or misleading.*/
        int st = 0 , end = s.size()-1;
        while(st<end){
            if(s[st]=='a'||'e'||'i'||'o'||'u'||'A'||'E'||'I'||'O'||'U'&&s[end]=='a'||'e'||'i'||'o'||'u'||'A'||'E'||'I'||'O'||'U'){
                swap(s[st++],s[end--]);
            }else if(s[st]=='a'||'e'||'i'||'o'||'u'||'A'||'E'||'I'||'O'||'U' && s[end]!='a'||'e'||'i'||'o'||'u'||'A'||'E'||'I'||'O'||'U'){
                end--;
            }else if(s[st]!='a'||'e'||'i'||'o'||'u'||'A'||'E'||'I'||'O'||'U' && s[end]=='a'||'e'||'i'||'o'||'u'||'A'||'E'||'I'||'O'||'U'){
                st++;
            }else{
                st++;
                end--;
            }
        }
        return s ;
    }
};
class Solution {
public:
    string reverseVowels(string s) {
        int st = 0 , end = s.size()-1;
        while(st<end){
            bool stVowel = (s[st]=='a'||s[st]=='e'||s[st]=='i'||s[st]=='o'||s[st]=='u'||s[st]=='A'||s[st]=='E'||s[st]=='I'||s[st]=='O'||s[st]=='U');
            bool endVowel = (s[end]=='a'||s[end]=='e'||s[end]=='i'||s[end]=='o'||s[end]=='u'||s[end]=='A'||s[end]=='E'||s[end]=='I'||s[end]=='O'||s[end]=='U');
            if(stVowel&&endVowel){
                swap(s[st++],s[end--]);
            }else if(!stVowel){
                st++;
            }else{
                end--;
            }
        }
        return s;
        }
    };
