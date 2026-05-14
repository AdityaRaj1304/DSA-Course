#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std ;
class Solution {//Dont work for more than 32 bits
public:
    int numSteps(string s) {
        int num = 0;
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {
            int bit = s[i] - '0';
            int power = n - i - 1;
            num +=bit << power;
        }

        int steps = 0;
        while (num > 1) {
            if ((num & 1) == 0) {
                num >>= 1;
                steps++;
            } else {
                num += 1;
                steps++;
            }
        }

        return steps;
    }
};
