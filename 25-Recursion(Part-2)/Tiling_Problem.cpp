#include<iostream>
using namespace std;
int tilling(int n ){
    if(n==0||n==1){
        return 1 ;
    }
    int ans1= tilling(n-1);//Vertical
    int ans2=tilling(n-2);//Horizontal
    return ans1 + ans2 ;
}
int main(){
    int n = 5;
    cout << tilling(n);
}