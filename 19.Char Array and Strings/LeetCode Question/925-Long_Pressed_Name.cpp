#include<iostream>
#include<string>
#include<vector>
using namespace std ;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0 , j= 0 , k ;
        int n = typed.length();
        int m = name.length();
        if(n<m){
            return false;
        }
        while(i<n){
            if(typed[i]==name[j]&&j<m){
                i++;
                j++;
            }else if(typed[i]!=name[j]){
                if(i>0 && typed[i]==typed[i-1]){ // Make sure to put i>0 condition
                    i++;
                }else{
                    return false;
                }
            }
}
        return j==m ; //Important Condition 
    }
};