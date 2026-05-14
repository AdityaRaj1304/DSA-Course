#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        vector<int>ans;
        for(int temp:asteroids){
            bool alive = true;
            while(!s.empty() && s.top()>0 && temp < 0){
                if(abs(temp)>abs(s.top())){
                    s.pop();
                }else if(abs(temp)==abs(s.top())){
                    s.pop();
                    alive=false;
                    break;
                }else{
                    alive=false;
                    break;
                }
            }
            if(alive){
                s.push(temp);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};