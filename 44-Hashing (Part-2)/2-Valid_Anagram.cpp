#include<bits/stdc++.h>
using namespace std;

bool majorityElement(string s ,string t){
    //s<char,freq>
    unordered_map<char,int>freq;
    for(int i = 0;i<s.size();i++){
        if(freq.count(s[i])){
            freq[s[i]]++;
        }else{
            freq[s[i]]=1;
        }
    }
    for(int i = 0;i<t.size();i++){
        if(freq.count(t[i])){
            freq[t[i]]--;
            if(freq[t[i]]==0){
                freq.erase(t[i]);
            }
        }else{
            return false;
        }
    }
    return freq.size()==0;
}

int main(){
    string s = "race" ,t ="care";
    string a = "tulip" , b="lipid";
    cout << majorityElement(s,t)<<endl;
    cout << majorityElement(a,b);
    return 0;
}