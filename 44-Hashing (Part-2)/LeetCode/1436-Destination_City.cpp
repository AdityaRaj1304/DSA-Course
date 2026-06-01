#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>s;
        for(vector<string>p:paths){
            s.insert(p[0]);
        }
        string dest ="";
        for(vector<string>p:paths){
            if(s.find(p[1])==s.end()){
                dest=p[1];
                return dest;
            }
        }
        return dest;
    }
};