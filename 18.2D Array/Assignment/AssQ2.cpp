#include<iostream>
#include<vector>
using namespace std;
int main(){
    int nums[ ][3] = { {1,4,9}, {11,4,3}, {2,2,3} };
    int sum = 0;
    for(int j = 0 ; j<3;j++){
        sum+=nums[1][j];
    }
    cout << "Sum of all elements of 2nd Row = " << sum;
    return 0 ;
}