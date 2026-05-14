#include<iostream>
using namespace std;
int power(int x ,int n){//Brute Force
    if(n==0){
        return 1;
    }
    return x * power(x,n-1);
}
int pow(int x , int n ){//Optimised Version [T.C.=O(log n)]
    if(n==0){
        return 1;
    }
    int half_power = pow(x,n/2);
    int half_power_square = half_power*half_power;
    if(n%2!=0){
        return x*half_power_square;
    }
    return half_power_square;
}
int main(){
    int num = 2;
    int power = 3;
    cout << pow(num,power);;
}