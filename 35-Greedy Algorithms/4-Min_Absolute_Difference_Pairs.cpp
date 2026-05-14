#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>A={1,2,3};
    vector<int>B={2,1,3};

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int minDiff=0;
    for(int i = 0 ;i<A.size();i++){
        minDiff+=abs(A[i]-B[i]);
    }
    cout << "Sum of Minimum Difference Between Pairs = "<< minDiff ;
    return 0;
}