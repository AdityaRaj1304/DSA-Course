#include<iostream>
using namespace std;

int main(){
    int n = 4;
    char ch = 'A';
    for(int i =1;i<=n;i++){
        for(int j =1;j<=i;j++){
            cout << "*";
        }
        for(int j =1;j<=2*(n-i);j++){
            cout << " ";
        }
        for(int j =1;j<=i;j++){
            cout << "*";
        }
        cout << endl;
    }
    for(int i =n-1;i>0;i--){
        for(int j =1;j<=i;j++){
            cout << "*";
        }
        for(int j =1;j<=2*(n-i);j++){
            cout << " ";
        }
        for(int j =1;j<=i;j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}