#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;
class Solution { // T.C. = O(n) but Space Complexity if O(n)
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            int best_buy[100000];
            best_buy[0]=INT_MAX;
            int max_profit= 0;
            for(int i = 1 ; i < n;i++){
                best_buy[i]=min(prices[i-1],best_buy[i-1]);
            }
            for(int i = 0 ; i < n ; i++){
                int curr_profit = prices[i]-best_buy[i];
                max_profit=max(curr_profit,max_profit);
            }
            return max_profit;
        }
    };
class Solution { // Optimised Version T.C. = O(n)  Space Complexity = O(1)
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            min_price = min(min_price, prices[i]);
            int curr_profit = prices[i] - min_price;
            max_profit = max(max_profit, curr_profit);
        }

        return max_profit;
    }
};
