#include<iostream>
#include<vector>
using namespace std;
void number_7(vector<vector<int>>&arr){
    int ans = 0 ;
    for(int i = 0 ; i < arr.size();i++){
        for(int j = 0 ; j < arr[0].size();j++){
            if(arr[i][j]==7){
                ans++;
            }
        }
    }
    cout << "Number of 7 in Array = "<< ans;
}
int main (){
    vector<vector<int>> vec = {{4,7,8},{8,8,7}};
    number_7(vec);
    return 0 ; 
}