#include<bits/stdc++.h>
using namespace std;

int maxAreaHistogram(vector<int>&heights){
    stack<int>s;
    int n = heights.size();
    vector<int>nsl(n,0);
    vector<int>nsr(n,0);

    //next Smaller Left
    for(int i = 0 ;i<n;i++){
        while(!s.empty() && heights[i]<=heights[s.top()]){
            s.pop();
        }
        if(!s.empty()){
            nsl[i]=s.top();
        }else{
            nsl[i]=-1;
        }
        s.push(i);
    }

    // emptying stack
    while(!s.empty()){
        s.pop();
    }

    //next Smaller right
    for(int i = n-1;i>=0;i--){
        while(!s.empty()&&heights[i]<=heights[s.top()]){
            s.pop();
        }
        if(!s.empty()){
            nsr[i]=s.top();
        }else{
            nsr[i]=n;
        }
        s.push(i);
    }

    int maxArea = 0;
    for(int i = 0 ;i<n;i++){
        int height = heights[i];
        int width = nsr[i]-nsl[i]-1;
        int area = height * width;
        maxArea =  max(maxArea,area);
    }
    cout << "Max Area Of Histogram: " << maxArea << endl;
    return maxArea;
}

int main(){
    vector<int>heights={2,1,5,6,2,3};
    maxAreaHistogram(heights);
    return 0;
}