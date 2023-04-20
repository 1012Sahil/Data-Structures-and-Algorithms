/*
LEETCODE - Medium : Longest Increasing Subsequence
Ques. Given an integer array nums, return the length of the longest strictly increasing subsequence.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int nums[])
    {
        // Tabulation solution
       vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int parent = ind - 1; parent >= -1; parent--)
            {
                int len = 0;
                // if nums[ind] > parent
                // either skip or take in sequence as it may be possible skipping may lead to a larger LIS
                if (parent == -1 || nums[ind] > nums[parent])
                {
                    len = max(0 + dp[ind + 1][parent + 1],
                    1 + dp[ind + 1][ind + 1]);
                }
                else // just skip and proceed to find next greater element
                len = 0 + dp[ind + 1][parent + 1];
                dp[ind][parent + 1] = len;
            }
        }
        return dp[0][0];        
    }
};

int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

/*
public:
// Intuitive approach - different than pick and not pick approach
// NOTE - This solution is necesaary to print the LIS
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int nums[])
    {
        // as the smallest LIS has to be 1, the index itself
        vector<int> dp(n, 1);
       
        int maxi = 1;
        // we are traversing the array for each index and checking what is the max LIS upto that index and
        // storing it in the dp array. We then return the max of the dp array as answer
        // Time Complexity : O(n^2)
        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (nums[prev] < nums[ind]) // if a greater LIS is found, store it in dp[ind]
                dp[ind] = max(dp[ind], 1 + dp[prev]);
            }
            maxi = max(maxi, dp[ind]);
        }
        return maxi;      
    }
*/

/*
NOTE - PRINTING THE LIS FORM THE PREVIOUS SOLUTION
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        // as the smallest LIS has to be 1, the index itself
        vector<int> dp(n, 1), hash(n); // hash will be used to backtrack to figure out LIS
       
        int maxi = 1;
        // we will keep track of the index where max LIS ends
        int lastIndex = 0;
        // we are traversing the array for each index and checking what is the max LIS upto that index and
        // storing it in the dp array. We then return the max of the dp array as answer
        // Time Complexity : O(n^2)
        // Intuitive approach different than pick and not pick approach
        for (int ind = 0; ind < n; ind++)
        {
            hash[ind] = ind; // initially, each element has LIS ending at themselves
            for (int prev = 0; prev < ind; prev++)
            {
                if (nums[prev] < nums[ind] && dp[ind] < 1 + dp[prev])
                {// if a greater LIS is found, store it in dp[ind]
                    dp[ind]= 1 + dp[prev];
                    // store the index of the last element in this LIS
                    hash[ind] = prev;
                }
            }
            if (dp[ind] > maxi)
            {
                maxi = dp[ind];
                // update lastIndex when we find a greater LIS
                lastIndex = ind;
            }
        }
        
        vector<int> lis(maxi);
        lis[0] = nums[lastIndex]; // first element has to be lastIndex
        int ind = 1; // 0 has already been taken care of
        while(hash[lastIndex] != lastIndex)
        // until the LIS ends at itself (when backtracking), continue
        {
            lastIndex = hash[lastIndex]; // remember, we have stored the previous 
            //element index in sequence
            lis[ind++] = nums[lastIndex]; // increment index after storing the previous element in lis
        }
        // as we backtracked, we need to reverse the answer
        reverse(lis.begin(), lis.end());
        return lis;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
*/

/*
THE BINARY SEARCH METHOD - A follow up approach to finding the LIS - Time Complexity: O(n log(n))
int longestSubsequence(int n, int nums[])
    {
        // What we are trying here is that instead of checking all the subsequences (which worsens
        // space complexity), we are proceeding to overwrite the LIS(s) so that we use only fix space O(n).
        // In this way, we can't backtrack to print LIS but can get the count, which is what we need!
        
        vector<int> temp;
        // we are starting the seq from index 0.
        temp.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            // if the new index is greater than the last inserted element, simply push it at back
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
            }
            else 
            {
                // if the new element resides between the elements already stored in temp,
                // then insert it at appropriate index
                
                // Iterator lower_bound (Iterator first, Iterator last, const val) lower_bound
                // returns an iterator pointing to the first element in the range [first,last) 
                // which has a value not less than ‘val’  and if the value is not present in 
                // the vector then it returns the end iterator.
                // to get index, we need to subtract temp.begin() from this pointer.
                // lower_bound uses binary search to return apt pointer
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                // after getting index, store the new element, essentially overwriting the previous one
                temp[ind] = nums[i];
            }
        }
        // return LIS
        return temp.size();
    }
*/

/*
MEMOIZATION SOLUTION
class Solution {
public:
    int f(int ind, int parent, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == nums.size())
        return 0;

        if (dp[ind][parent + 1] != -1)
        return dp[ind][parent + 1];

        int len = 0;
        // if nums[ind] > parent
        // either skip or take in sequence as it may be possible skipping may lead to a larger LIS
        if (parent == -1 || nums[ind] > nums[parent])
        {
            len = max(0 + f(ind + 1, parent, nums, dp),
            1 + f(ind + 1, ind, nums, dp));
        }
        else // just skip and proceed to find next greater element
        len = 0 + f(ind + 1, parent, nums, dp);
        return dp[ind][parent + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size() + 1, -1));
        return f(0, -1, nums, dp);        
    }
};
*/