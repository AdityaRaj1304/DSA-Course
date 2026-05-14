#include<iostream>
#include<string>
using namespace std ;
bool Anagram(string str1 , string str2){
    if(str1.length()!=str2.length()){
        cout << "Invalid Anagram\n";
        return false ;
    }
    int count[26]={0};
    for(int i = 0 ; i < str1.length();i++){
        int index = str1[i]-'a';
        count[index]++;
    }
    for(int i = 0 ; i<str2.length();i++){
        int idx = str2[i]-'a';
        if(count[idx]==0){
            cout <<"Invalid Anagram\n";
            return false ;
        }
        count[idx]--;
    }
    cout << "Valid Anagram\n";
    return true;
}
int main (){
    string x , y ;
    cout << "Enter Word 1 : ";
    getline(cin,x);
    cout << "Enter Word 2 : ";
    getline(cin,y);
    Anagram(x,y);
}