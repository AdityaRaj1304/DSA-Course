#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans ;
        for(int i = 0 ; i <=n ; i++){
            int temp = 0;
            while(i){
            if((i&1)==1){
                temp++;
            }
            i<<=1;
        }
        ans.push_back(temp);
    }
    return ans;
}
};