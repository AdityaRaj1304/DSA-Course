#include<iostream>
#include<cstring>
using namespace std;
void reverse(char * arr , int n){
    int st = 0 , end = n-1;
    while(st < end){
        swap(arr[st++],arr[end--]);
    }
    cout << arr ;
}
int main(){
    char arr[] = "Aditya";
    reverse(arr,strlen(arr));
    return 0 ;
}