/*
For problems of partition DP, we follow these general three steps - (these problems have tough patterns)
-> Start with the entire block or array and express in terms of index
-> Try all partitions (Use a loop if necessary)
-> Return the best possible 2 partitions
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(N * N) * N ~ O(N^3)
// Space Complexity : O(N^2) + O(N) (auxiliary + recursive stack space)

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int j, int arr[], vector<vector<int>> &dp)
    {
        // if single matrix, as end dimension is same as start, we return 0 as no operations required
        if (i == j)
        return 0;
        
        if (dp[i][j] != -1)
        return dp[i][j];
        
        // to find the minimum number of multiplications
        int mini = 1e9;
        // k represents where we do the partition, for eg : ABCD -> A|BCD or AB|CD or ABC|D,
        // where internal partitions also occur for recursive calls
        // recall that number of operations of multiplying 2 matrices of size aXb and bXc = a*b*c
        for (int k = i; k < j; k++)
        {
            // we are calculating all operations by recursively calling partitions of groups 
            // until we have a single matrix remaining
            int steps = (arr[i - 1] * arr[k] * arr[j])+ f(i, k, arr, dp) + f(k + 1, j, arr, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // PARTITION
        vector<vector<int>> dp(N, vector<int> (N + 1, -1));
        return f(1, N - 1, arr, dp);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}

/*
TABULATION METHOD
int matrixMultiplication(int N, int arr[])
    {
        // PARTITION 
        vector<vector<int>> dp(N + 1, vector<int> (N + 1, 0));
        
        for (int i = N - 1; i >= 1; i--)
        {
            for (int j = i + 1; j < N; j++)
            {
                // to find the minimum number of multiplications
                int mini = 1e9;
                // k represents where we do the partition, for eg : ABCD -> A|BCD or AB|CD or ABC|D,
                // where internal partitions also occur for recursive calls
                // recall that number of operations of multiplying 2 matrices of size aXb and bXc = a*b*c
                for (int k = i; k < j; k++)
                {
                    // we are calculating all operations by recursively calling partitions of groups 
                    // until we have a single matrix remaining
                    int steps = (arr[i - 1] * arr[k] * arr[j])+ dp[i][k] + dp[k + 1][j];
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N - 1];
    }
*/