#include<iostream>
#include<vector>
using namespace std ;
class Solution { //T.C. = O(n)
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = ans ^ (start+(2*i));
        }
        return ans ;
    }
};
class Solution {
public:
    int xorOperation(int n, int start) {
        int offset = start >> 1; // same as start / 2
        int xorRange = xorUpto(offset + n - 1) ^ xorUpto(offset - 1);
        return xorRange << 1; // Multiply by 2
    }

    int xorUpto(int x) {
        if (x < 0) return 0;
        if (x % 4 == 0) return x;
        if (x % 4 == 1) return 1;
        if (x % 4 == 2) return x + 1;
        return 0; // x % 4 == 3
    }
};
