#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int solve(int n , vector<int>&cost, vector<int>& dp){
        if(n==0) return cost[0];
        if(n== 1) return cost[1];
        if(dp[n] != -1) return dp[n];
        int l = solve(n-1,cost,dp);
        int k = solve(n-2,cost,dp); 
        return dp[n] = cost[n] + min(l,k);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(solve(n - 1, cost,dp), solve(n - 2, cost,dp));
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> cost(n);
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    Solution ob;
    cout << ob.minCostClimbingStairs(cost) << endl;
    return 0;
}   