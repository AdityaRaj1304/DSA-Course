#include<iostream>
#include<string>
using namespace std;
int brute_force(string str){
    int ans = 0;
    for(int i = 0 ; i < str.size();i++){
        for(int j = i ; j<str.size();j++){
            if(str[i]==str[j]){
                ans++;
            }
        }
    }
    return ans;
}
int countsubstr(string str,int i , int j , int n){
    if(n==1){
        return 1;
    }
    if(n<=0){
        return 0 ;
    }
    int res = countsubstr(str,i+1,j,n-1)+countsubstr(str,i,j-1,n-1)-countsubstr(str,i+1,j-1,n-2);
    if(str[i]==str[j]){
        res++;
    }
    return res;
}
int optimised(string str){
    int ans = 0;
    int letter[26]={0};
    for(int i =0;i<str.size();i++){
        letter[str[i]-'a']++;
    }
    for(int i = 0 ; i <26;i++){
        int a = letter[i];
        ans+=(a*(a+1))/2;
    }
    return ans;
}
int main (){
    string s ="abcab";
    int n = s.size();
    cout <<brute_force(s)<<endl;
    cout<<countsubstr(s,0,n-1,n)<<endl;
    cout <<optimised(s);
}