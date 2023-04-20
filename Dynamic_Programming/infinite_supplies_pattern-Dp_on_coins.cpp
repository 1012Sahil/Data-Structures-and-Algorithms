/*
Ques : Coin change - Leetcode

class Solution {
public:
int f(int ind, vector<int> &coins, int N, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            // if we can still pick up a bag, return its value
            if (N % coins[ind] == 0)
            return N / coins[ind];
            else return 1e9;
        }
        
        if (dp[ind][N] != -1)
        return dp[ind][N];
        
        // not pick element
        int notPick = f(ind - 1, coins, N, dp);
        // pick element
        int pick = 1e9;
        // if bag is picked, reduce the weight we can pick next by wt[ind]
        if (N >= coins[ind])
        pick = 1 + f(ind, coins, N - coins[ind], dp);
        // max wt we can pick must be returned
        return dp[ind][N] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int N) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (N + 1, -1));
        int ans = f(n - 1, coins, N, dp);
        if (ans == 1e9)
        return -1;
        else return ans;
    }
};
*/