#include<iostream>
#include<string>
using namespace std;
void binString(int n ,int lastPlace , string ans){
    if(n==0){
        cout << "Ans : " << ans << endl;
        return;
    }
    if(lastPlace!=1){
        binString(n-1,0,ans+'0');
        binString(n-1,1,ans+'1');
    }else{
        binString(n-1,0,ans+'0');
    }
}
int main(){
    int n = 4;
    string ans ;
    binString(n,0,ans);
}