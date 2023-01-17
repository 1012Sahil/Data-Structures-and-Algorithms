#include <bits/stdc++.h>
using namespace std;

// Time Compleity : O(2^N * N)
// Space Complexity : O(N)
void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    // Print all subsequences of sum exactly equal to K
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    // if you want to print in increasing length of subsequence, then swap the recursive calls

    // take or pick the particular index into subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];
    printS(ind + 1, ds, s, sum, arr, n);
    s -= arr[ind];
    ds.pop_back();

    // not pick, or take condition, this element is not added to your subsequence
    printS(ind + 1, ds, s, sum, arr, n);
}

bool print1S(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    // Print exactly one subsequence of sum exactly equal to K
    if (ind == n)
    {
        // condition satisfied
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        // condition not satisfied
        else
            return false;
    }
    // if you want to print in increasing length of subsequence, then swap the recursive calls

    // take or pick the particular index into subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];
    if (print1S(ind + 1, ds, s, sum, arr, n) == true)
        return true;
    s -= arr[ind];
    ds.pop_back();

    // not pick, or take condition, this element is not added to your subsequence
    if (print1S(ind + 1, ds, s, sum, arr, n) == true)
        return true;

    return false;
}

int countS(int ind, int s, int sum, int arr[], int n)
{
    // Count the number of subsequence of sum exactly equal to K
    if (s > sum)
    return 0;
    if (ind == n)
    {
        // condition satisfied
        if (s == sum)
        {
            return 1;
        }
        // condition not satisfied
        else
            return 0;
    }
    // if you want to print in increasing length of subsequence, then swap the recursive calls

    // take or pick the particular index into subsequence
    s += arr[ind];
    int l = countS(ind + 1, s, sum, arr, n);
    s -= arr[ind];

    // not pick, or take condition, this element is not added to your subsequence
    int r = countS(ind + 1, s, sum, arr, n);

    return l + r;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printS(0, ds, 0, sum, arr, n);
    print1S(0, ds, 0, sum, arr, n);
    cout << countS(0, 0, sum, arr, n) << endl;
    return 0;
}