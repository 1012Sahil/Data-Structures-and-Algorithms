/*
Ques - Longest Common Subsequence - LEETCODE MEDIUM

Given two strings text1 and text2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with
some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/

/*
Recursive approach - Will give TLE as time complexity is exponential

class Solution {
public:
    int f(int ind1, int ind2, string &text1, string &text2)
    {
        // if any index goes negative, it signifies end of string, so return 0
        if (ind1 < 0 || ind2 < 0)
        return 0;
        
        // char match - check previous characters also + 1 for match
        if (text1[ind1] == text2[ind2])
        return 1 + f(ind1 - 1, ind2 - 1, text1, text2);
        // no match - means either we reduce text1 or text2 and 
        // compare which subsequence is bigger
        return 0 + max(f(ind1 - 1, ind2, text1, text2), 
        f(ind1, ind2 - 1, text1, text2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        // Draw the recursive tree for better understanding
        return f(n1 - 1, n2 - 1, text1, text2);
    }
};
*/
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

class Solution
{
    public:
    int f(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        // if any index goes negative, it signifies end of string, so return 0
        if (ind1 < 0 || ind2 < 0)
        return 0;
        if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
        // char match - check previous characters also + 1 for match
        if (text1[ind1] == text2[ind2])
        return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, text1, text2, dp);
        // no match - means either we reduce text1 or text2 and 
        // compare which subsequence is bigger
        return dp[ind1][ind2] = max(f(ind1 - 1, ind2, text1, text2, dp), 
        f(ind1, ind2 - 1, text1, text2, dp));
    }

    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n1, int n2, string s1, string s2)
    {
        // memoization - (ind1, ind2) as 2D dp vector parameters
        // DP[i][j] represents the LCS of text1[0 ... i] & text2[0 ... j].
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return f(n1 - 1, n2 - 1, s1, s2, dp);
    }
};

int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

/*
TABULATION SOLUTION
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n1, int n2, string text1, string text2)
    {
        // memoization - (ind1, ind2) as 2D dp vector parameters
        // DP[i][j] represents the LCS of text1[0 ... i] & text2[0 ... j].
        // tabulation - shifting the index
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
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
        return dp[n1][n2];
    }
};
*/

/*
TABULATION - SPACE OPTIMIZED
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n1, int n2, string text1, string text2)
    {
        // memoization - (ind1, ind2) as 2D dp vector parameters
        // DP[i][j] represents the LCS of text1[0 ... i] & text2[0 ... j].
        // tabulation - shifting the index - space optimised
        vector<int> prev(n2 + 1, 0), cur(n2 + 1, 0);
        // as we can see, in the previous solution, we had the base case where if ind < 0 we return 0
        // but that base case fails in tabulation as we are not able to reach negatie index in loops
        // To deal with that, we will shift the index of tabulation by 1
        
        for (int ind1 = 1; ind1 <= n1; ind1++)
        {
            for (int ind2 = 1; ind2 <= n2; ind2++)
            {
                // char match - check previous characters also + 1 for match - remember to shift index
                if (text1[ind1 - 1] == text2[ind2 - 1])
                    cur[ind2] = 1 + prev[ind2 - 1];
                
                // no match - means either we reduce text1 or text2 and 
                // compare which subsequence is bigger
                else
                cur[ind2] = max(prev[ind2], 
                cur[ind2 - 1]);
            }
            prev = cur;
        }
        return prev[n2];
    }
};
*/