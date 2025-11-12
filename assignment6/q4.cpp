#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>&dp) {
        int m = matrix[0].size();
        if (j < 0 || j >= matrix[0].size()) return 1e8;
        if (i == 0) return matrix[0][j];
        if(dp[i][j] != -101) return dp[i][j];
        int ans = INT_MAX;
        for (int k = 0; k < m; k++) {
            if (k == j) continue; 
            ans = min(ans, matrix[i][j] + solve(i - 1, k, matrix, dp));
        }
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MAX;
        vector<vector<int>>dp(n+1, vector<int>(m+1, -101));
        for (int j = 0; j < m; j++)
            ans = min(ans, solve(n-1, j, grid,dp));
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout << sol.minFallingPathSum(grid) << endl; 
    return 0;
}