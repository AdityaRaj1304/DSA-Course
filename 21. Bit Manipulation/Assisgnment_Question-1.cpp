#include<iostream>
using namespace std;
void clearbitsinrange(int num , int j , int i ){
    int left = (~0)<<(j+1);
    int right = (1<<i)-1 ;
    int mask = left | right ;
    num = num & mask ;
    cout << "Answer : " << num ;
}
int main (){
    clearbitsinrange(15,3,1);
}