#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
  public:
    int solve(int n , vector<int>&height, vector<int>&dp){
        if(n==0) return 0;
        if(n== 1) return dp[n] = abs(height[n] - height[n-1]);
        if(dp[n] != -1) return dp[n];
        int l = solve(n-1,height,dp) + abs(height[n] - height[n-1]);
        int k = solve(n-2,height,dp) + abs(height[n] - height[n-2]);
        return dp[n] = min(l,k);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        // vector<int>dp(n + 1 , -1);
        // return solve(n-1,height,dp);

        vector<int>dp(n + 1 , -1);
        
        dp[0] = 0 ;
        dp[1] = abs(height[1] - height[0]);
        
        for(int i = 2 ; i< n ;i++){
            int l = dp[i-1] + abs(height[i] - height[i-1]);
            int k = dp[i-2] + abs(height[i] - height[i-2]);
            dp[i] = min(l,k);
        }
        
        return dp[n-1];
    }
};


int main() {
    Solution sol;
    vector<int> height = {30, 10, 60, 10, 60, 50};
    cout << sol.minCost(height) << endl;
    return 0;
}