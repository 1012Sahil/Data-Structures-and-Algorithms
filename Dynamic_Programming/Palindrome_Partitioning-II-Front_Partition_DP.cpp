#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // checking for plaindrome between the given indices
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, int n, string &s, vector<int> &dp)
    {
        // if we reach end, we simply return 0 as no more partitions are possible
        if (i == n)
            return 0;

        // memoization
        if (dp[i] != -1)
            return dp[i];

        int minCuts = INT_MAX;
        // traverse from i to end, and make a partititon where the string is palindrome
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                // when we find one portion is palindrome, we create a partition, so we have 1 + recurToFindRest
                int cost = 1 + f(j + 1, n, s, dp);
                minCuts = min(minCuts, cost);
            }
        }
        // return minimum partitions
        return dp[i] = minCuts;
    }

    int palindromicPartition(string s)
    {
        int n = s.size();
        // tabulation now
        vector<int> dp(n + 1, 0);

        // base case already handled
        for (int i = n - 1; i >= 0; i--)
        {
            int minCuts = INT_MAX;
            // traverse from i to end, and make a partititon where the string is palindrome
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, s))
                {
                    // when we find one portion is palindrome, we create a partition, so we have 1 + recurToFindRest
                    int cost = 1 + dp[j + 1];
                    minCuts = min(minCuts, cost);
                }
            }
            // return minimum partitions
            dp[i] = minCuts;
        }

        // our code does a partition at the end, so we ignore that
        return dp[0] - 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}