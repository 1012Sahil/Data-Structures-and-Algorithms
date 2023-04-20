#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMin(string text1)
    {
        /* We know that the longest palindromic subsequence is to be kept intact and we just need to insert
        all the characters that aren't part of LPS. So ans = n - LPS
        */
        // to find the LPS, we just need to pass the string and its reverse in the LCS function as we know that the LPS would be the LCS of the string and its reverse as a palindrome is the same whether read backwards or forwards
        int n1 = text1.size();
        int n2 = n1;
        string text2 = text1;
        reverse(text2.begin(), text2.end());
        // memoization - (ind1, ind2) as 2D dp vector parameters
        // DP[i][j] represents the LCS of text1[0 ... i] & text2[0 ... j].
        // tabulation - shifting the index
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // as we can see, in the previous solution, we had the base case where if ind < 0 we return 0
        // but that base case fails in tabulation as we are not able to reach negatie index in loops
        // To deal with that, we will shift the index of tabulation by 1
        // handle base cases
        for (int i = 0; i <= n1; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= n2; j++)
            dp[0][j] = 0;

        for (int ind1 = 1; ind1 <= n1; ind1++)
        {
            for (int ind2 = 1; ind2 <= n2; ind2++)
            {
                // char match - check previous characters also + 1 for match - remember to shift index
                if (text1[ind1 - 1] == text2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];

                // no match - means either we reduce text1 or text2 and
                // compare which subsequence is bigger
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2],
                                         dp[ind1][ind2 - 1]);
            }
        }
        return n1 - dp[n1][n2];
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
        cout << ob.countMin(str) << endl;
    }
    return 0;
}