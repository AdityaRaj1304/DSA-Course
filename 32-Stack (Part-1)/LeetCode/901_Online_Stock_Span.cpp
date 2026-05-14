#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
public:
    stack<int>s;
    vector<int>stock;
    StockSpanner() {
        
    }
    
    int next(int price) {
        stock.push_back(price);
        int i = stock.size()-1;
        int span = 0;
        while(!s.empty() && price >=stock[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span = i+1;
        }else{
            int prevHigh = s.top();
            span = i -prevHigh;
        }
        s.push(i);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */