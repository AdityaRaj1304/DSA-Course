#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int>fib;
        fib.push_back(0);
        fib.push_back(1);
        for(int i =2;i<50;i++){
            fib[i]=fib[i-1]+fib[i-2];
            if(fib[i]>k){
                break;
            }
        }
        int ans =0;
        int idx = fib.size()-1;
        while(k){
            if(fib[idx]<=k){
                k-=fib[idx];
                ans++;
            }
            idx--;
        }
        return ans;
    }
};

