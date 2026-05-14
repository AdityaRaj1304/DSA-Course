#include<iostream>
#include<string>
using namespace std;
void removeDuplicates(string str,string ans , int i , int map[26]){
    if(i==str.size()){
        cout << "Ans : " << ans ;
        return ;
    }
    int mapIdx=(int)(str[i]-'a');
    if(map[mapIdx]){
        removeDuplicates(str,ans,i+1,map);
    }else{
        map[mapIdx]=true;
        removeDuplicates(str,ans+str[i],i+1,map);
    }
}
void duplicates(string str , string ans , int map[26]){//More Complex
    if(str.size()==0){
        cout << "Ans : " << ans;
        return;
    }
    int n = str.size();
    char ch = str[n-1];
    int mapIdx = int(str[n-1]-'a');
    str=str.substr(0,n-1);
    if(map[mapIdx]){
        duplicates(str,ans,map);
    }else{
        map[mapIdx]=true;
        duplicates(str,ch+ans,map);
    }
}
int main(){
    string str = "apnnacollege";
    string ans ="";
    int map[26] = {false};
    //removeDuplicates(str,ans,0,map);
    duplicates(str,ans,map);
    return 0 ;
}