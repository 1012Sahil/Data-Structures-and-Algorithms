/*
Ques - Cherry Pickup II - LEETCODE HARD
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents
the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.

// DP solution - Memoization
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int c = grid[0].size();
        // NOW WE WILL USE TABULATION TO REDUCE STACK SPACE
        // A 3-D dp vector is needed to store i,j1,j2 combinations
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(c, vector<int>(c, -1)));

        // step 1 - take care of base case
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        // step 2 - express every state in terms of for loops
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < c; j1++)
            {
                for (int j2 = 0; j2 < c; j2++)
                {
                    int maxi = -1e8;
                    for (int delj1 = -1; delj1 <= 1; delj1++)
                    {
                        for (int delj2 = -1; delj2 <= 1; delj2++)
                        {
                            int value = 0;
                            if (j1 == j2)
                            {
                                // if paths overlap, count cherries only once
                                value = grid[i][j1];
                            }
                            else
                            {
                                value = grid[i][j1] + grid[i][j2];
                            }
                            if (j1 + delj1 >= 0 && j1 + delj1 < c &&
                                j2 + delj2 >= 0 && j2 + delj2 < c)
                                value += dp[i + 1][j1 + delj1][j2 + delj2];
                            else
                                value += -1e8;
                            maxi = max(value, maxi);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][c - 1];
    }
};
*/
/*
// Dp solution - Tabulation class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int c = grid[0].size();
        // NOW WE WILL USE TABULATION TO REDUCE STACK SPACE
        // NOW WE WILL SPACE OPTIMISE THE ABOVE APPROACH BY CONVERTING 3D dp - > 2D dp
        // A 2-D front and cur dp array is needed to store j1,j2 combinations
        vector<vector<int>> front(c, vector<int>(c, -1));
        vector<vector<int>> cur(c, vector<int>(c, -1));
        // step 1 - take care of base case
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                if (j1 == j2)
                    front[j1][j2] = grid[n - 1][j1];
                else
                    front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        // step 2 - express every state in terms of for loops
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < c; j1++)
            {
                for (int j2 = 0; j2 < c; j2++)
                {
                    int maxi = -1e8;
                    for (int delj1 = -1; delj1 <= 1; delj1++)
                    {
                        for (int delj2 = -1; delj2 <= 1; delj2++)
                        {
                            int value = 0;
                            if (j1 == j2)
                            {
                                // if paths overlap, count cherries only once
                                value = grid[i][j1];
                            }
                            else
                            {
                                value = grid[i][j1] + grid[i][j2];
                            }
                            if (j1 + delj1 >= 0 && j1 + delj1 < c &&
                                j2 + delj2 >= 0 && j2 + delj2 < c)
                                value += front[j1 + delj1][j2 + delj2];
                            else
                                value += -1e8;
                            maxi = max(value, maxi);
                        }
                    }
                    cur[j1][j2] = maxi;
                }
            }
            front = cur;
        }
        return cur[0][c - 1];
    }
};
*/