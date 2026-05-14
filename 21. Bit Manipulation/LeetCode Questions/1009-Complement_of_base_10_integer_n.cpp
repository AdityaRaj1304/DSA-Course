#include<iostream>
using namespace std ;
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1 ;
        }
        unsigned mask = 1;
        while(mask<=n){
            mask= mask<<1;
        }
        mask -= 1;
        return mask ^ n ;
    }
};