#include<iostream>
#include<vector>
#include<cmath>
using namespace std ;
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_area=0,max_diagonal=0;
        for(int i = 0 ; i < dimensions.size();i++){
            int length = dimensions[i][0];
            int width=dimensions[i][1];
            int diagonal = length*length+width*width;
            if(diagonal>max_diagonal){
                max_diagonal=diagonal;
                max_area = length*width;
            }else if(diagonal==max_diagonal){
                max_area=max(max_area,length*width);
            }
    }
    return max_area;
}
};