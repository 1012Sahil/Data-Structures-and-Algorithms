/*
QUES - SUBSET SUM PROBLEM - GFG MEDIUM
Given an array of non-negative integers, and a value sum, determine if there is a subset of the
given set with sum equal to given sum.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool f(int ind, vector<int> &arr, int sum, vector<vector<int>> &dp)
    {
        // if target is reached, return true
        if (sum == 0)
            return true;
        // if we are at 0 index, remember that if target == arr[0], we just pick this and return true
        if (ind == 0)
            return (arr[0] == sum);
        // taking care of overlapping sub problems
        if (dp[ind][sum] != -1)
            return dp[ind][sum];
        bool notTake = f(ind - 1, arr, sum, dp);
        bool take = false;
        if (sum >= arr[ind])
            take = f(ind - 1, arr, sum - arr[ind], dp);
        return dp[ind][sum] = (take || notTake);
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        // Applying memoization to improve time complexity
        // 2D DP vector is needed to store boolean value of ind, sum
        // vector of dimensions n, target + 1 is needed
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return f(arr.size() - 1, arr, sum, dp);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0;
}

/*
TABULATION FOR REDUCING RECURSION STACK SPACE
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(int ind, vector<int> &arr, int sum, vector<vector<int>> &dp)
    {
        // if target is reached, return true
        if (sum == 0)
        return true;
        // if we are at 0 index, remember that if target == arr[0], we just pick this and return true
        if (ind == 0)
        return (arr[0] == sum);
        // taking care of overlapping sub problems
        if (dp[ind][sum] != -1)
        return dp[ind][sum];
        bool notTake = f(ind - 1, arr, sum, dp);
        bool take = false;
        if (sum >= arr[ind])
        take = f(ind - 1, arr, sum - arr[ind], dp);
        return dp[ind][sum] = (take || notTake);
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // Applying memoization to improve time complexity
        // 2D DP vector is needed to store boolean value of ind, sum
        // vector of dimensions n, target + 1 is needed 
        vector<vector<bool>> dp(arr.size(), vector<bool> (sum + 1, 0));
        
        // TABULATION METHOD
        // step 1 - handle base cases
        for (int i = 0; i < arr.size(); i++)
        dp[i][0] = true;
        // when target = arr[ind] and ind = 0
        dp[0][arr[0]] = true;
        
        // step 2 - convert the recursion into iterative approach
        
        for (int ind = 1; ind < arr.size(); ind++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (target >= arr[ind])
                take = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = (take || notTake);
            }
        }
        return dp[arr.size() - 1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
*/

/*
SPACE OPTIMISED TABULATION SOLUTION
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(int ind, vector<int> &arr, int sum, vector<vector<int>> &dp)
    {
        // if target is reached, return true
        if (sum == 0)
        return true;
        // if we are at 0 index, remember that if target == arr[0], we just pick this and return true
        if (ind == 0)
        return (arr[0] == sum);
        // taking care of overlapping sub problems
        if (dp[ind][sum] != -1)
        return dp[ind][sum];
        bool notTake = f(ind - 1, arr, sum, dp);
        bool take = false;
        if (sum >= arr[ind])
        take = f(ind - 1, arr, sum - arr[ind], dp);
        return dp[ind][sum] = (take || notTake);
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // Applying memoization to improve time complexity
        // 2D DP vector is needed to store boolean value of ind, sum
        // vector of dimensions n, target + 1 is needed 
        // Now will space optimise it, and use only a 1D vector 
        vector<bool> prev(sum + 1, 0), cur(sum + 1, 0);
        
        // TABULATION METHOD
        // step 1 - handle base cases
        prev[0] = cur[0] = true;
        // when target = arr[ind] and ind = 0
        prev[arr[0]] = true;
        
        // step 2 - convert the recursion into iterative approach
        
        for (int ind = 1; ind < arr.size(); ind++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool notTake = prev[target];
                bool take = false;
                if (target >= arr[ind])
                take = prev[target - arr[ind]];
                cur[target] = (take || notTake);
            }
            prev = cur;
        }
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
*/