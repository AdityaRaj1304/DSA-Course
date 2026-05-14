#include<iostream>
#include<cstring>
using namespace std ;
void palindrome(char *arr , int n){
    int st = 0 ;
    int end = n-1;
    while(st<end){
        if(arr[st++]!=arr[end--]){
            cout << "Not a palindrome\n";
            return;
        }
    }
    cout << "Valid Palindrome";
}
int main (){
    char arr[50];
    cout << "Enter Word : ";
    cin.getline(arr,50);
    palindrome(arr,strlen(arr));
}