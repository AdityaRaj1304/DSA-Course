#include<iostream>
using namespace std ;

void maxSumSubarray_BruteForceApproach(int*arr , int n){
    //Time Complexity = O(n^3)
    int maxsum = INT_MIN ;
    for(int start = 0 ; start < n ; start++){
        for(int end = start; end < n ;end++){
            int currsum = 0 ;
            for(int i = start;i<=end;i++){
                currsum+=arr[i];
            }
            cout << currsum << ",";
            maxsum=max(currsum,maxsum);
        }
        cout << endl;
    }
    cout << "Maximum Subarray Sum :" << maxsum << endl;
}
void maxSumSubarray_OptimisedApproach(int *arr , int n){
    // Time Complexity : O(n^2)
    int maxsum = INT_MIN;
    for(int start = 0 ; start < n ; start++){
        int currsum = 0 ;
        for(int end = start ; end < n ; end++){
            currsum += arr[end];
            maxsum = max(currsum,maxsum);
        }
    }
    cout << "Maximum Sum of Array : " << maxsum << endl;
}
void max_SumSubarray_KadanesAlgorithm(int *arr , int n){
    //Time Complexity : O(n)
    int maxsum = INT_MIN;
    int currsum = 0 ;
    for(int i = 0 ; i < n ; i++){
        currsum= currsum + arr[i];
        maxsum = max(currsum,maxsum);
        if(currsum<0){
            currsum=0;
        }
    }
    cout << "Maximum Sum of Array : " << maxsum << endl;
}
int main(){
    int arr[6] = {-2,3,-23,4,5,6};
    int n = 6;
    maxSumSubarray_BruteForceApproach(arr,n);
    maxSumSubarray_OptimisedApproach(arr,n);
    max_SumSubarray_KadanesAlgorithm(arr,n);
return 0 ;
}