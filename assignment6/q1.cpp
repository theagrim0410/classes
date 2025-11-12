#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>&arr , int i , int j, vector<vector<int>>&dp){
        if (i < 0 || j < 0) return 0;
        if (arr[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(arr , i-1 , j,dp) + solve(arr, i , j-1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1)) ;
        return solve(obstacleGrid,n-1,m-1,dp);
    }
};

int main(){
    Solution sol;
    vector<vector<int>> obstacleGrid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl; 
    return 0;
}