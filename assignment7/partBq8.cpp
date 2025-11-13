#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return grid[i][j];
        if (i < 0 || j < 0) return INT_MAX; 
        if(dp[i][j] != -1) return dp[i][j];
        int a = solve(grid, i - 1, j,dp);
        int b = solve(grid, i, j - 1,dp);
        return  dp[i][j] = grid[i][j] + min(a, b);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        // return solve(grid, n - 1, m - 1, dp);

        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        dp[0][0] = grid[0][0];
        for (int j = 1; j < m; j++) dp[0][j] = grid[0][j] + dp[0][j - 1];
        for (int i = 1; i < n; i++) dp[i][0] = grid[i][0] + dp[i - 1][0];
        for(int i = 1  ; i < n ; i++){
            for(int j = 1 ; j< m ; j++){
                int a = dp[i-1][j];
                int b = dp[i][j-1];
                dp[i][j] = grid[i][j] + min(a,b);
            }
        }

        return dp[n-1][m-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << sol.minPathSum(grid) << endl;
    return 0;
}
