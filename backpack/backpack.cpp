#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <iostream>
using namespace std;

int unboundedKnapsack(int W, int wt[], int val[], int idx,
    vector<vector<int> >& dp)
{

    // Base Case
    // if we are at idx 0.
    if (idx == 0) {
        return (W / wt[0]) * val[0];
    }
    // If the value is already calculated then we will
    // previous calculated value
    if (dp[idx][W] != -1)
        return dp[idx][W];
    // There are two cases either take element or not take.
    // If not take then

    int notTake
        = 0 + unboundedKnapsack(W, wt, val, idx - 1, dp);
    // if take then weight = W-wt[idx] and index will remain
    // same.
    int take = INT_MIN;
    if (wt[idx] <= W) {
        take = val[idx]
            + unboundedKnapsack(W - wt[idx], wt, val,
                idx, dp);
    }
    return dp[idx][W] = max(take, notTake);
}

// Driver code
int main()
{
    int W = 17;
    int val[] = { 15, 29, 35, 46 };
    int wt[] = { 2, 5, 6, 7 };
    int n = sizeof(val) / sizeof(val[0]);
    vector<vector<int> > dp(n, vector<int>(W + 1, -1));
    cout << unboundedKnapsack(W, wt, val, n - 1, dp);
    return 0;
}