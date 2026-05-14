#include<iostream>
using namespace std ;
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        if(!(n&(n-1))){
            for(int i=0 ; i < 32 ; i+=2){
                int bitmask = 1<<i;
                if((n&bitmask)==0){
                    continue;
                }else{
                    return true;
                    break;
                }
            }
        }
        return false ;
    }
    bool isPowerOfFour(int n) {//More Efficient Version (No Loop)
    return n > 0 && !(n & (n - 1)) && (n & 0x55555555);
}
};
    /*You can eliminate the loop entirely using a bitmask:
    !(n & (n - 1)) → check for power of two
    0x55555555 → binary 01010101 01010101 01010101 01010101 (all even bit positions set)
    (n & 0x55555555) ensures the 1 is in an even position*/
