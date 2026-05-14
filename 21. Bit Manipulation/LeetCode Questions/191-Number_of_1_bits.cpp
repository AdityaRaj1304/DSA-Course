#include<iostream>
using namespace std ;
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0 ;
        for(int i = 0 ; i < 32 ; i++){
            if(!(n&(1<<i))){
                continue;
            }else{
                count++;
            }
        }
        return count ;
    }
    int hammingWeight(int n) {//Most Efficient Version (Brian Kernighan’s Algorithm)
    int count = 0;
    while(n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

};