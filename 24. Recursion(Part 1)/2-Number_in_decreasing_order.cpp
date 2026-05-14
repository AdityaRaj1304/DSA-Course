#include<iostream>
using namespace std ;
void print(int n){
    if(n==0){
        return;
    }
    cout << n << " "; //kaam
    print(n-1); //faith , next call
}
int main(){
    int n = 105;
    print(n);
    return 0 ;
}