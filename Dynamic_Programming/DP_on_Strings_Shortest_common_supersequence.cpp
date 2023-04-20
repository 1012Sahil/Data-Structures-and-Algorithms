/*
LEETCODE HARD - Shortest Common Supersequence 
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.
If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t
(possibly 0) results in the string s.


class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        // First we will find the len_lcs as we know that the lcs will be common to both strings so we
        // have to take it only once, then we will take all the characters from X and Y that are 
        // not part of the lcs in addition to those present in lcs.
        int n1 = s.size();
        int n2 = t.size();
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
                if (s[ind1 - 1] == t[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                
                // no match - means either we reduce text1 or text2 and 
                // compare which subsequence is bigger
                else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], 
                dp[ind1][ind2 - 1]);
            }
        }
        
        // We have created the DP table for the longest common subsequence, we will use this table to figure out the scs 
        // refer striver playslist - DP 31. Shortest Common Supersequence
        // traversing the dp table from end till we exhaust all the letters
        string ans = "";
        int i = n1, j = n2;
        while (i > 0 && j > 0)
        {
            // if both chars are same, we take this char one time only to avoid repition
            if (s[i - 1] ==  t[j - 1])
            { 
                ans += s[i - 1];
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1])
            {
                // if not same then we check the max condition in lcs and pick that character
                ans += s[i - 1];
                i--;
            }
            else
            {
                ans += t[j - 1];
                j--;
            }
        }
        // when one word exhausts, it is possible that the other word has not as their lengths might differ, so we take care of that too
        while (i > 0)
        {
            ans += s[i - 1];
            i--;
        }

        while (j > 0)
        {
            ans += t[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;        
    }
};
*/