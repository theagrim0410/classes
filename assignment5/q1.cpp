#include <bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
  public:
    const int MOD = 1e9 + 7;
    int solve(int n , int r , vector<vector<int>>&dp){
        if(r>n) return 0;
        if(r == 0 || r == n) return 1;
        if(dp[n][r] != -1) return dp[n][r];
        
        return dp[n][r] = (solve(n-1, r-1,dp) + solve(n-1,r,dp))%MOD;
    }
    int nCr(int n, int r) {
        vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));
        return solve(n,r,dp);
    
    }
};

int main() {
    int n, r;
    cin >> n >> r;
    Solution ob;
    cout << ob.nCr(n, r) << endl;
    return 0;
}


