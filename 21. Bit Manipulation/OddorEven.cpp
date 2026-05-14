#include<iostream>
using namespace std ;
void isOddorEven (int num){
    if(!(num&1)){
        cout << "Even Number\n";
    }else{
        cout << "Odd Number \n";
    }
}
int main (){
    int num ;
    cout << "Enter Number : ";
    cin >> num ;
    isOddorEven(num);
    return 0 ;
}