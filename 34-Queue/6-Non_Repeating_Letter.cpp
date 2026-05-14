#include<bits/stdc++.h>
using namespace std;

void nonRepeatingLetter(string str){
    queue<char>Q;
    int freq[26] = {0};
    for(char ch : str){
        Q.push(ch);
        freq[ch-'a']++;
        while(!Q.empty() && freq[Q.front()-'a']>1){
            Q.pop();
        }
        if(Q.empty()){
            cout << "-1\n";
        }else{
            cout << Q.front() << endl;
        }
    }
}

int main(){
    string s = "aabccxb";
    nonRepeatingLetter(s);
    return 0;
}