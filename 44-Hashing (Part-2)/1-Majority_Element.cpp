#include<bits/stdc++.h>
using namespace std;

void majorityElement(vector<int>nums){
    int n = nums.size();
    unordered_map<int,int>m;  //element,freq
    for(int num:nums){
        if(m.count(num)){
            m[num]++;
        }else{
            m[num]=1;
        }
    }
    for(auto it:m){
        if(it.second>n/3){
            cout << it.first << " ";
        }
    }
    cout << endl;
}

int main(){
    vector<int>nums1={1,3,5,2,1,3,1,5,1,5,5};
    vector<int>nums2={2,2};
    majorityElement(nums1);
    majorityElement(nums2);
    return 0;
}