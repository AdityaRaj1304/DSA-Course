#include<iostream>
#include<cstring>
#include<string>
using namespace std ;
void lowercase_vowels(string s){
    int count = 0 ;
    for(int i = 0 ; i < s.length();i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            count++;
        }
    }
    cout << "No of lowercase vowels in string '" << s << "' are " << count << endl ;
}
int main (){
    string s ;
    cout << "Enter String : ";
    getline(cin , s);
    lowercase_vowels(s);
    return 0 ; 
}