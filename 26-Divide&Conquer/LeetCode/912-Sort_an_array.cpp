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
/* Alternative Quick Sort Implementation -Dont use it time complexity O(n^2) in worst case
class Solution {
public:
    int partition_asc(vector<int>&arr, int st , int end){
    int i = st-1 , pivot =arr[end];
    for(int j = st ; j < end ;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[end]);
    return i;
}
void quickSortasc(vector<int>&arr , int st , int end){
    if(st>=end){
        return;
    }
    int pivotIdx=partition_asc(arr,st,end);
    quickSortasc(arr,st,pivotIdx-1);//left side
    quickSortasc(arr,pivotIdx+1,end);//right side
}
    vector<int> sortArray(vector<int>& nums) {
        quickSortasc(nums,0,nums.size()-1);
        return nums;
    }
};
*/