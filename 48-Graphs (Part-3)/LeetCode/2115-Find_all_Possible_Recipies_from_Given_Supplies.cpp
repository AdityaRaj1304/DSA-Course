#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>graph;
        unordered_map<string,int>inDeg;
        unordered_set<string>s;

        for(string supply :supplies){
            s.insert(supply);
        }

        for(string&rec:recipes){
            inDeg[rec]=0;
        }

        for(int i =0;i<recipes.size();i++){
            string recipe = recipes[i];
            for(string ing:ingredients[i]){
                if(s.find(ing)==s.end()){
                    graph[ing].push_back(recipe);
                    inDeg[recipe]++;
                }
            }
        }

        queue<string>q;
        for(auto x:inDeg){
            if(x.second==0){
                q.push(x.first);
            }
        }
        vector<string>ans;
        while(q.size()>0){
            string curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto&ing:graph[curr]){
                inDeg[ing]--;
                if(inDeg[ing]==0){
                    q.push(ing);
                }
            }
        }
        return ans;
    }
};