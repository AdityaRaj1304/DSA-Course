#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int merge(vector<int>&arr , int st , int mid , int end){
    int i = st , j = mid+1;
    int count = 0;
    vector<int>temp;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }else{
            count+=mid-i+1;
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }
    for(int i = st ,x=0; i<=end;i++){
        arr[i]=temp[x++];
    }
    return count;
}
int merge_sort(vector<int>&arr , int st , int end){
    if(st>=end){
        return 0;
    }
    int mid = st+(end-st)/2;
    int ans = 0;
    ans+=merge_sort(arr,st,mid);
    ans+=merge_sort(arr,mid+1,end);
    ans+= merge(arr,st,mid,end);
    return ans;
}
    int inversionCount(vector<int> &arr) {
        return merge_sort(arr,0,arr.size()-1);
    }
};
int main(){
    vector<int>arr={6,3,5,2,7};
    Solution s;
    cout << s.inversionCount(arr);
}