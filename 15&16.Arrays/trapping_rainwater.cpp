#include<iostream>
#include<vector>
using namespace std ;
void trap_water(int *arr , int n ){
    int left_max[20000];
    int right_max[20000];
    left_max[0]=arr[0];
    right_max[n-1]=arr[n-1];
    for(int i = 1 ; i< n ; i++){
        left_max[i]=max(left_max[i-1],arr[i-1]);
        cout << left_max[i] << ",";
    }
    cout << endl ;
    for(int i = n-2 ; i>=0 ; i--){
        right_max[i]=max(right_max[i+1],arr[i+1]);
        cout << right_max[i] << ",";
    }
    cout << endl ;
    int water_trapped = 0 ;
    for(int i = 0 ; i<n;i++){
        int currwater = min(left_max[i],right_max[i])-arr[i];
        if(currwater>0){
            water_trapped+=currwater;
        }
    }
    cout << "Water Trapped : " << water_trapped;
}
class Solution { // with Vectors
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max (n) , right_max(n);
        left_max[0]=height[0];
        right_max[n-1]=height[n-1];
        int water_trapped = 0;
        for(int i = 1 ; i < n ; i++){
            left_max[i]=max(left_max[i-1],height[i-1]);
            right_max[n-1-i]=max(height[n-i],right_max[n-i]);
        } 
        for(int i = 0 ; i < n ; i++){
            int curr_water =(min(left_max[i],right_max[i]))-height[i];
            if(curr_water>0){
                water_trapped+=curr_water;
            }
        }
        return water_trapped;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        right_max[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int water_trapped = 0;
        for (int i = 0; i < n; i++) {
            water_trapped += min(left_max[i], right_max[i]) - height[i];
        }

        return water_trapped;
    }
};
class Solution { // Optimised Version (Two Pointers)
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0 , right = n-1;
        int left_max=0 , right_max=0;
        int water_trapped = 0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=left_max){
                    left_max=height[left];
                }else{
                    water_trapped += left_max-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=right_max){
                    right_max=height[right];
                }else{
                    water_trapped+=right_max-height[right];
                }
                right--;
            }
        }
        return water_trapped;
    }
};
int main (){
    int height[7]= {4,2,0,6,3,2,5};
    int n = sizeof(height)/sizeof(int);   
    trap_water(height,n);
}