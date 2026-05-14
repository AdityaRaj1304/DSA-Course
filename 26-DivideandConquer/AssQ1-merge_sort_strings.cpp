#include<iostream>
#include<vector>
#include<string>
using namespace std;
void merge(vector<string>&arr,int st, int mid , int end){
    int i = st , j = mid+1;
    vector<string>temp;
    while(i<=mid&&j<=end){
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
    for(int i =st ,x=0; i <=end;i++){
        arr[i]=temp[x++];
    }
}
void mergeSortstring(vector<string>&arr, int st , int end){
    if(st>=end){
        return;
    }
    int mid= st+(end-st)/2;
    mergeSortstring(arr,st,mid);
    mergeSortstring(arr,mid+1,end);
    merge(arr,st,mid,end);
}
void printArr(vector<string>arr ,int n){
    for(int i = 0 ; i<n;i++){
        cout << arr[i] << " "; 
    }
}
int main(){
    vector<string>arr={"sun", "earth", "mars", "mercury"};
    mergeSortstring(arr,0,arr.size()-1);
    printArr(arr,arr.size());
}