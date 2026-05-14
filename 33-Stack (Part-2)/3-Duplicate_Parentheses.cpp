#include<bits/stdc++.h>
using namespace std;

bool isDuplicate(string str){
    stack<char>s;
    for(int i = 0 ; i<str.size();i++){
        char ch = str[i];
        if(ch != ')'){ // Non Closing Condition
            s.push(ch);
        }else{
            if(s.empty()){
                return false;
            }
            if(s.top() == '('){
                return true;
            }
            while(!s.empty() && s.top()!='('){
                s.pop();
            }
            if(!s.empty()){
                s.pop();
            } 
        }
    }
    return false;
}

int main(){
    string str1 = "((a+b)+(c+d))";
    string str2 = "((a+b))";
    cout << isDuplicate(str1) << endl;
    cout << isDuplicate(str2);
    return 0;
}