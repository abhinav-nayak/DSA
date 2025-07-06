// Problem: https://neetcode.io/problems/buy-and-sell-crypto?list=neetcode150 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r=0;
        int maxProfit=0;
        int profit;

        // Approach - dynamic sliding window
        while(r<prices.size()){
            if(prices[l]<=prices[r]) {
                profit = prices[r]-prices[l];
                if(profit>maxProfit)
                    maxProfit=profit;
            }
            else {
                // if prices[r] < prices[l], means 'r' is a better day to buy a stock. Make l=r;
                l=r;
            }
            r++;
        }

        return maxProfit;
    }
};

// Time complexity - O(n)
// Space complexity - O(1)
