#include<bits/stdc++.h>
using namespace std;

void countDistinct(vector<int>nums){
    unordered_set<int>s;
    for(int num:nums){
        s.insert(num);
    }
    cout << "Elements: ";
    for(int num:s){
        cout << num << " ";
    }
    cout << "\nDistinct Elements: " << s.size();
}

int main(){
    vector<int>nums={4,3,2,5,6,7,3,4,2,1};
    countDistinct(nums);
    return 0;
}