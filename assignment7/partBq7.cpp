#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int solve(int i , int j ,vector<vector<int>>&dp){
        if(i == 0 || j == 0) return 1 ;
        if(dp[i][j] != -1) return dp[i][j];
        return  dp[i][j] = solve(i-1, j, dp) + solve(i , j-1 , dp);
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m+1, vector<int> (n+1, -1)) ;
        // return solve(m-1 , n-1 , dp);

        vector<vector<int>> dp(m+1, vector<int> (n+1, -1)) ;
        for(int i = 0 ; i<m ; i++) dp[i][0] = 1;
        for(int j = 0 ; j<n ; j++) dp[0][j] = 1;

        for(int i = 1 ;i<m ;i++){
            for (int j = 1 ;j < n ; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;
    int m = 3, n = 7;
    cout << sol.uniquePaths(m, n) << endl;
    return 0;
}   