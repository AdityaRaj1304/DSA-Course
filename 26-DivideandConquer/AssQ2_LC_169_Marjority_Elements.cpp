#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {//Moore's Voting Algo(One Type)-O(n)
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0 , ans = 0;
        for(int i = 0 ; i < nums.size();i++){
            if(freq==0){
                ans=nums[i];
            }
            if(ans==nums[i]){
                freq++;
            }else{
                freq--;
            }
        }
        return ans;
    }
};



class Solution {//Sorting-O(nlogn)
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int freq=1;
        int ans=nums[0];
        for(int i = 1 ; i < n ; i++){
            if(nums[i-1]==nums[i]){
                freq++;
                ans =nums[i];
            }else{
                freq=1;
            }
            if(freq>n/2){
                return ans;
            }
        }
        return ans;
    }
};



int element(vector<int>& nums){//Moore Voting Algo Classical Approach - O(n)
    int n  = nums.size();
    int count = 0;
    int candidate = 0 ;
    //Step1-Finding the candidate
    for(int i:nums){
        if(count==0){
            candidate=i;
        }
        if(i==candidate){
            count++;
        }else{
            count--;
        }
    }
    count=0;
    //Step 2 - Verification of Candidate
    for(int i:nums){
        if(i==candidate){
            count++;
        }
    }
    if(count>n/2){
        return candidate;
    }
    return -1;
}



//Divide&Conquer Approach
int countRange(vector<int>&arr,int num ,int st , int end){
    int count = 0 ;
    for(int i = st ; i<=end;i++){
        if(arr[i]==num){
            count++;
        }
    }
    return count;
}
int majorityElement(vector<int>&arr,int st , int end){
    //base case; the only element in an array of size 1 is the majority element.
    if(st==end){
        return arr[st];
    }

    // recurse on left and right halves of this slice.
    int mid = st+(end-st)/2;
    int left =majorityElement(arr,st,mid);
    int right=majorityElement(arr,mid+1,end);

    //// if the two halves agree on the majority element, return it.
    if(left==right){
        return left;
    }
    // otherwise, count each element and return the "winner".
    int leftcount=countRange(arr,left,st,end);
    int rightcount=countRange(arr,right,st,end);
    if(leftcount>rightcount){
        return left;
    }else{
        return right;
    }

}


int main(){
    vector<int>arr={2,2,1,1,1,2,2};
    cout << majorityElement(arr,0,arr.size()-1);
}