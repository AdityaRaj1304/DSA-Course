#include<bits.\stdc++.h>
using namespace std;
class Solution { // Time Limit Exceeded on LeetCode since it needed to be solved using DP
public:
    int uniquePaths(int m, int n) {
        int ans =ways(0,0,m,n);
        return ans;
    }
    int ways(int r , int c , int m , int n){
        if(r>=m||c>=n){
            return 0;
        }
        if(r==m-1&&c==n-1){
            return 1;
        }
        int val1=ways(r,c+1,m,n);
        int val2=ways(r+1,c,m,n);
        return val1+val2;
    }
};
// class Solution { // Using PnC Formula still it wont work for bigger factorial number (TLE)
// public:
//     int uniquePaths(int m, int n) {
//         int a = m - 1, b = n - 1;
//         long long c = 1;
//         long long x = 1;

//         int divisor = max(a, b);
//         int d = min(a, b);

//         for (int i = divisor + 1; i <= a + b; i++) {
//             c *= i;
//         }
//         for (int i = 2; i <= d; i++) {
//             x *= i;
//         }

//         return c / x;
//     }
// };