#include<bits/stdc++.h>
using namespace std;

bool compare(pair<double,int>p1 , pair<double,int>p2){
    return p1.first> p2.first;
}

void fractionalKnapsack(vector<int>&val,vector<int>&wt,int W){
    int n = val.size();
    int ans =0;
    vector<pair<double,int>>ratio(n,make_pair(0.0,0));
    for(int i = 0; i<n;i++){
        double r = val[i]/wt[i];
        ratio[i]=make_pair(r,i);
    }

    sort(ratio.begin(),ratio.end(),compare);

    for(int i = 0;i<n;i++){
        int idx = ratio[i].second;
        if(wt[idx]<=W){
            ans+=val[idx];
            W-=wt[idx];
        }else{
            ans+=ratio[i].first * W;
            W=0;
            break;
        }
    }
    cout << "Maximum Value of the Knapsack: " << ans ;
}

int main(){
    vector<int>values={60,100,120};
    vector<int>weights={10,20,30};
    int W = 50;
    fractionalKnapsack(values,weights,W);
    return 0;
}
