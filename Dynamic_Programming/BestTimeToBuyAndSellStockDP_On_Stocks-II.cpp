/*
LEETCODE - MEDIUM : Best Time to Buy and Sell Stock II
Ques.You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and / or sell the stock.You can only hold at most one share of the
stock at any time. However, you can buy it then immediately sell it on the same day.Find and return the
maximum profit you can achieve.

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // if buy == 1 -> you can buy stock, otherwise you cannot
        // Submitted, now use tabulation with space optimisation
        vector<int> fwd(2, 0);

        // handle base cases
        // already handled as we initialised array with all 0s

        for (int ind = prices.size() - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                int profit = 0;
                // if we buy a stock, we invest prices[i] and if we sell, we gain prices[i], so we use - for buy and + for sell, so prices[sell] - prices[i] = profit
                // either buy this stock, or look to buy some other stock
                if (buy)
                    profit = max(-prices[ind] + fwd[0],
                                 0 + fwd[1]);
                else // either sell this stock, or sell it at another price later
                    profit = max(prices[ind] + fwd[1],
                                 0 + fwd[0]);

                fwd[buy] = profit;
            }
        }
        return fwd[1];
    }
};
*/