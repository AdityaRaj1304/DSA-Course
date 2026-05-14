#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>&arr, int st , int mid , int end){
        int i = st , j = mid+1;
        vector<int>temp;
        while(i<=mid && j <=end){
            if(arr[i]<arr[j]){
                temp.push_back(arr[i++]);
            }else{
                temp.push_back(arr[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(arr[i++]);
        }
        while(j<=end){
            temp.push_back(arr[j++]);
        }
        for(int i = st , x=0 ; i<=end;i++){
            arr[i]=temp[x++];
        }
    }
    void mergeSort(vector<int>&arr , int st , int end){
        if(st>=end){
            return;
        }
        int mid=st+(end-st)/2;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};