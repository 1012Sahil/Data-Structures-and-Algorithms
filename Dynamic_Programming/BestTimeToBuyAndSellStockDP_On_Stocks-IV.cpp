/*
LEETCODE - HARD : Best Time to Buy and Sell Stock IV
Ques. You are given an integer array prices where prices[i] is the price of a given stock on the ith day,
and an integer k. Find the maximum profit you can achieve. You may complete at most k transactions:
i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously 
(i.e., you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // atmost k transactions can be made
        // Tabulation - using a 3D vector
        // And finally space optimising this approach
        vector<vector<int>> fwd(k + 1, vector<int> (2, 0)), cur(k + 1, vector<int> (2, 0));

        int profit = 0;
        for (int ind = prices.size() - 1; ind >= 0; ind--)
        {
            for (int limit = k; limit >= 0; limit--)
            {
                for (int buy = 0; buy <= 1; buy++)
                {
                    if (limit > 0)
                    {
                        if (buy)
                        {
                            // either buy stock or choose to buy later
                            profit = max(-prices[ind] + 
                            fwd[limit - 1][0], 
                            0 + fwd[limit][1]);
                        }
                        else
                        {
                            // either sell stock or choose to sell later
                            profit = max(prices[ind] + 
                            fwd[limit][1], 
                            0 + fwd[limit][0]);
                        }
                    }
                    else
                    {
                        if (!buy)
                        {
                            // sell or not
                            profit = max(prices[ind] + 
                            fwd[limit][1],
                            0 + fwd[limit][0]);
                        }
                        else
                        {
                            // just move to next index as you can't buy
                            profit = fwd[limit][buy];
                        }
                    }
                    cur[limit][buy] = profit;
                }
            }
            fwd = cur;
        }
        return fwd[k][1];        
        
    }
};
*/