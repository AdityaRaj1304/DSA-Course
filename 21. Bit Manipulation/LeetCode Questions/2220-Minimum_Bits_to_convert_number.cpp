#include<iostream>
using namespace std ;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flip = 0;
        while(start||goal){
            int ld1 = start&1;
            int ld2 = goal & 1 ;
            if(ld1 != ld2){
                flip++;
            }
            start=start>>1;
            goal=goal>>1;
        }
        return flip ;
    }
};