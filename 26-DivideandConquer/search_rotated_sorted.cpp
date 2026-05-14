#include<iostream>
#include<vector>
using namespace std;
int search(int*arr,int st , int end , int tar){
    if(st>end){
        return -1;
    }
    int mid = st+(end-st)/2;
    if(arr[mid]==tar){
        cout << "Start: " << st << " End: " << end << endl;
        return mid;
    }
    if(arr[st]<=arr[mid]){//L1
        if(arr[st]<=tar&&tar<=arr[mid]){
            cout << "Start: " << st << " End: " << end<< endl;
            return search(arr,st,mid-1,tar);//left half
        }else{
            cout << "Start: " << st << " End: " << end<< endl;
            return search(arr,mid+1,end,tar);//right half
        }
    }else{//L2
        if(arr[mid]<=tar && tar <=arr[end]){
            cout << "Start: " << st << " End: " << end<< endl;
            return search(arr,mid+1,end,tar);//right half
        }else{
            cout << "Start: " << st << " End: " << end<< endl;
            return search(arr,st,mid-1,tar);//left half
        }
    }
}
int main(){
    int num[7]={4,5,6,7,0,1,2};
    int n = sizeof(num)/sizeof(num[0]);
    int target=0;
    cout << search(num,0,n-1,target);
}