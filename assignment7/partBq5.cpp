#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int solve( vector<int>& nums, int i,vector<int>&dp, int n) {
        if (i == n) return nums[n];
        if (i < n) return 0;
        if(dp[i] != -1) return dp[i];
        int l = nums[i] + solve(nums, i - 2,dp, n);
        int m = solve(nums, i - 1,dp, n);
        return dp[i] = max(l, m);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n ,-1);
        if(n < 4) return *max_element(nums.begin(), nums.end());
        int temp = solve(nums,n - 1, dp, 1);
        fill(dp.begin(), dp.end(), -1);
        return max(temp, solve(nums, n - 2, dp, 0));
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,1};
    cout << sol.rob(nums) << endl;
    return 0;
}