#include<iostream>
using namespace std ;
void getithbit(int num , int i ){
    int bitmask = 1<<i;
    if(!(num&bitmask)){
        cout << "0";
    }else{
        cout << "1";
    }
}
void setithbit(int num , int i){
    int bitmask = 1 << i;
    cout << (num|bitmask);    
}
void clearithbit(int num , int i){
    int bitmask = (~(1<<i));
    cout << (num&bitmask);
}
int main (){
    int n , i ;
    cout << "Enter Number :";
    cin >> n ;
    cout << "Enter Bit : ";
    cin >> i ;
    getithbit(n,i);
    cout << endl ;
    setithbit(n,i);
    cout << endl ;
    clearithbit(n,i);
    return 0 ;
}