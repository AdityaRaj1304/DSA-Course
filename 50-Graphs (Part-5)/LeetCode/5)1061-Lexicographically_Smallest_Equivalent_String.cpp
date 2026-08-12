#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DisjointSet{
public:
    int n ;
    vector<int>par;

    DisjointSet(int n){
        this->n=n;
        for(int i=0;i<n;i++){
            par.push_back(i);
        }
    }

    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]);
    }
    
    void unionSet(int u,int v){
        int parU = find(u);
        int parV = find(v);
        if(parU==parV){
            return;
        }else if(parU<parV){
            par[parV]=parU;
        }else{
            par[parU]=parV;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet dsu(26);
        for(int i =0;i<s1.size();i++){
            dsu.unionSet(s1[i]-'a',s2[i]-'a');
        }
        string ans="";
        for(char ch:baseStr){
            ans+=(char)dsu.find(ch-'a')+'a';
        }
        return ans;
    }
};