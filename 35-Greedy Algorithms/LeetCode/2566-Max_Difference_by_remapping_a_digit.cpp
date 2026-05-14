#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string n = to_string(num);
        char temp1 ='11';
        char temp2 ='11';
        bool change1 = false;
        bool change2 = false;
        for(int i = 0 ;i<s.size();i++){
            if(s[i]!='9' && !change1){
                temp1=s[i];
                s[i]='9';
                change1=true;
            }
            if(s[i]==temp1){
                s[i]='9';
            }
            if(n[i]!='0' && !change2){
                temp2=n[i];
                n[i]='0';
                change2=true;
            }
            if(n[i]==temp2){
                n[i]='0';
            }
        }
        int max = stoi(s);
        int min = stoi(n);
        return max-min;
    }
};