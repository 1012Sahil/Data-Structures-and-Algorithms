#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int f(int ind, int W, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            // if we can still pick up a bag, return its value
            if (W >= wt[ind])
                return val[ind];
            else
                return 0;
        }

        if (dp[ind][W] != -1)
            return dp[ind][W];

        // not pick element
        int notPick = f(ind - 1, W, wt, val, n, dp);
        // pick element
        int pick = 0;
        // if bag is picked, reduce the weight we can pick next by wt[ind]
        if (W >= wt[ind])
            pick = val[ind] + f(ind - 1, W - wt[ind], wt, val, n, dp);
        // max wt we can pick must be returned
        return dp[ind][W] = max(pick, notPick);
    }

    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Using dp to optimise the recursive approach!
        // 2D dp vector to store value at (ind, W) - signifies max value that can be taken for (ind, W)
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        return f(n - 1, W, wt, val, n, dp);
    }
};

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}

/*
class Solution
{
    public:
     //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Using dp to optimise the recursive approach!
        // 2D dp vector to store value at (ind, W)
        // Now Using Tabulation method
        vector<vector<int>> dp(n, vector<int> (W + 1, 0));
        // handle base cases
        for (int i = 0; i <= W; i++)
            if (i >= wt[0])
            dp[0][i] = val[0];
        
        for (int ind = 1; ind < n; ind++)
        {
            for (int w = 0; w <= W; w++)
            {
                int notPick = dp[ind - 1][w];
                // pick element
                int pick = 0;
                // if bag is picked, reduce the weight we can pick next by wt[ind]
                if (w >= wt[ind])
                pick = val[ind] + dp[ind - 1][w - wt[ind]];
                // max wt we can pick must be returned
                dp[ind][w] = max(pick, notPick);
            }
        }
        return dp[n - 1][W];
    }
};
*/

/*
class Solution
{
    public:
     //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Using dp to optimise the recursive approach!
        // 2D dp vector to store value at (ind, W)
        // Now Using Tabulation method
        vector<vector<int>> dp(n, vector<int> (W + 1, 0));
        // handle base cases
        for (int i = 0; i <= W; i++)
            if (i >= wt[0])
            dp[0][i] = val[0];
        
        for (int ind = 1; ind < n; ind++)
        {
            for (int w = 0; w <= W; w++)
            {
                int notPick = dp[ind - 1][w];
                // pick element
                int pick = 0;
                // if bag is picked, reduce the weight we can pick next by wt[ind]
                if (w >= wt[ind])
                pick = val[ind] + dp[ind - 1][w - wt[ind]];
                // max wt we can pick must be returned
                dp[ind][w] = max(pick, notPick);
            }
        }
        return dp[n - 1][W];
    }
};
*/