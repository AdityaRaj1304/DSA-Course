#include<iostream>
#include<string>
using namespace std ;
class Solution {
public:
    int strStr(string haystack, string needle) {
        string x = needle ;
        int a = haystack.find(x);
        return a ;
    }
};