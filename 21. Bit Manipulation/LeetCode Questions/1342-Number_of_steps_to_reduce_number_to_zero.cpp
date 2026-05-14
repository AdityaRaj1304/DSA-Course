#include<iostream>
using namespace std ;
class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0 ;
        while(num > 0){
            if(num%2==0){
                num /= 2;
            }else{
                num -= 1;
            }
            steps++;
        }
        return steps ;
    }
};
class Solution {//OPtimal Approach
public:
    int numberOfSteps(int num) {
        int steps = 0 ;
        while(num>0){
        if(!(num&1)){
            steps +=1;
        }else{
            steps+=2;
        }
        num = num>>1;
    }
    if(steps>0){
        steps-=1;
    }
    return steps;
    }
};