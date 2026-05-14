#include<iostream>
using namespace std ;
void updateithbit(int num , int i , int val){
    num = num & ~(1<<i);
    num = num | (val << i);
    cout << num ;
}
int main (){
    int n , i , val;
    cout << "Enter Number : ";
    cin >> n ;
    cout << "Enter Bit : ";
    cin >> i ;
    cout << "Enter Value : ";
    cin >> val ;
    cout << "Result : ";
    updateithbit(n,i,val);
}
    