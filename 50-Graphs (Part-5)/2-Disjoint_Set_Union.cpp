#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DisjointSet{
public:
    int n;
    vector<int>par,rank;

    DisjointSet(int n){
        this->n=n;
        rank.assign(n,0); //Better Way
        for(int i =0;i<n;i++){
            par.push_back(i);
            //rank.push_back(0);
        }
    }

    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]); //Path Compression
    }

    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);
        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
    }
};

int main(){
    DisjointSet ds(6);
    ds.unionByRank(0,2);
    cout << ds.find(2)<<endl;
    ds.unionByRank(1,3);
    ds.unionByRank(2,5);
    ds.unionByRank(0,3);
    cout << ds.find(3);
    ds.unionByRank(0,4);
    return 0;
}