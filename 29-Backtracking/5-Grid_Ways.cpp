#include <bits/stdc++.h>
using namespace std;
int gridWays(int r , int c , int n , int m,string ans){
    if(r>=n||c>=m){
        return 0;
    }
    if(r==n-1&&c==m-1){// (||)also works but for this question only
        cout << ans << "\n";
        return 1;
    }

    //Right
    int val1=gridWays(r,c+1,n,m,ans+"R");

    //Down
    int val2=gridWays(r+1,c,n,m,ans+"D");
    return val1+val2;
}
int main(){
    int n = 4 , m =4;
    string s;
    int ans = gridWays(0,0,n,m,s);
    cout << ans;
    return 0;
}