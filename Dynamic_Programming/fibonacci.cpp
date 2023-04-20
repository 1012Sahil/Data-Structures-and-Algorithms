#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(n) + O(n) = O(n)
//                     |      |
//                   vector recursion call stack

int f(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

int main()
{
    // We know that we encounter ovrlapping subproblems and we can optimise the usual recurive solution
    // by storing the solutions of the problems we have solved and use this instead of solving them again!
    int n;
    cin >> n;
    // Recursive soluion using DP - Memoization (Top-Down)
    vector<int> dp(n + 1, -1);
    cout << f(n, dp);
    // Tabulation (Bottom up)
    // Space optimised iterative solution using DP - Space Complexity : O(1)
    int prev2 = 0;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curi = prev1 + prev2;
        prev2 = prev1;
        prev1 = curi;
    }
    cout << prev1;
    return 0;
}
