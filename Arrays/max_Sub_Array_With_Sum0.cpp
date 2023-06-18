/*PREFIX SUM CONCEPT MAINLY!*/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this function*/

class Solution
{
public:
    int maxLen(vector<int> &A, int n)
    {
        /* Why did prefixSum algo work here? Notice that when we calculate prefixSum for each index, if we
        get repeated the same prefixSum as somewhere before, it means that sum of elements between these
        occurences must have been zero as the sum from first occurence to curr didn't change.
        We can use this fact to calculate the subArray with sum 0

        Eg - A = 15, -2, 2, -8, 1, 7, 10, 23
     PrefixSum = 15, 13, 15, 7, 8, 15, 25, 48
                 ^        ^         ^
                 |        |         |
         At these indices, prefixSum repeats, meaning we have these subarrays with sum 0
         1 -> -2, 2
         2 -> -2, 2, -8, 1, 7
         3 -> -8, 1, 7

         Out of these 2nd one is longest and we return ans = 5
        */

        int prefixSum = 0;
        // map will store the index of the first occurence of a prefixSum
        unordered_map<int, int> m;
        // will hold the maxLen of subarray with sum = 0
        int maxLen = 0;
        m[0] = -1; // if no subarray with sum 0 exists, then return len as -1
        for (int i = 0; i < n; i++)
        {
            prefixSum += A[i];
            // if prefixSum doesn't have an occurence, then add index to map
            if (m.find(prefixSum) == m.end())
                m.insert({prefixSum, i});
            // len of subarray with sum 0 = curIndex of prefixSum - firstOccurenceIndex of prefixSum
            // if first occurence is this one only, ensures len = 0 as i == m[prefixSum]
            int curLen = i - m[prefixSum];
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends