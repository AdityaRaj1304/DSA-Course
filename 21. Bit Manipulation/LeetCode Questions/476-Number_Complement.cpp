#include<iostream>
using namespace std ;
class Solution { //Mask need to be unsigned int for the code for very large numbers 
public:
    int findComplement(int num) {
        unsigned int mask = 1 ;
        while(mask<=num){
            mask = mask<<1;
        }
        mask = mask - 1 ;
        num = num ^ mask ;
        return num ;
    }
};
class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1; 
        int bits = 0 ;
        int temp = num ;
        while(temp!=0){
            bits++;
            temp = temp>>1;
        }
        unsigned int mask = 1;
        mask = (mask<<bits)-1;
        num = num ^ mask;
        return num ;
    }
};

int main (){
    int num = 4;
    Solution x ;
    cout << x.findComplement(num);
}