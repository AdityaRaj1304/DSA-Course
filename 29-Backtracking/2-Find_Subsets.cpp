#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printSubsets(string str , string subset){
    if(str.size()==0){
        cout << subset << endl;
        return;
    }
    char ch = str[0];
    printSubsets(str.substr(1,str.size()-1),subset+ch); // Yes choice
    printSubsets(str.substr(1,str.size()-1),subset); // No choice
}
int main(){
    string str ="abc" , subset="";
    printSubsets(str,subset);
    return 0 ;
}