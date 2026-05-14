#include<iostream>
#include<string>
using namespace std;
bool string_swap(string s1 , string s2){//Brute Force Approach by Me 
    if(s1.length()!=s2.length()){
        cout << "Different Word\n";
        return false;
    }
    for(int i = 0 ; i < s2.length() ; i++){
        for(int j = i+1 ; j < s2.length();j++){
            swap(s2[i],s2[j]);
            if(s1==s2){
                cout << "Same Word\n";
                return true ;
            }else{
                swap(s2[i],s2[j]);
            }
        }
    }
    cout << "Different Word\n";
    return false;
}
bool areAlmostEqual(string s1, string s2) { //OPtimised Approach 
    if (s1.length() != s2.length()) {
        return false;
    }

    char diffChar1, diffChar2;
    int diff = 0;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            if (!diff) {
                diffChar1 = s1[i];
                diffChar2 = s2[i];
            } else {
                if (s1[i] != diffChar2 || s2[i] != diffChar1) {
                    return false;
                }
            }
            diff++;
        }

        if (diff > 2) {
            return false;
        }
    }

    if (diff == 1) {
        return false;
    }

    return true;
}

 
int main(){
    string s1 = "bank" , s2 = "fast";
    string_swap(s1,s2);
    return 0;
}