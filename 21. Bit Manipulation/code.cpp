#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int numSteps(string s){
        int num = 0 ;
        int n = s.length();
        for(int i = n-1 ; i >=0 ;i--){
            int x = 0;
            num += s[i]*pow(2,x);
            x++;
        }
        cout << num ;
        return num;
    }
int main (){
    string s = "1101";
    int n = s.length() ;
    cout << n <<endl ;
    int num = 0;
    for(int i = n-1; i >=0 ;i--){
            int bit = s[i]-'0';
            int power = n-i-1;
            num+=bit * pow(2,power);
        }
        cout << num ;
    }