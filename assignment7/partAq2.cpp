#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(int i, int sum, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (i < 0) {
            return (sum == target) ? 1 : 0;
        }
        if (dp[i][sum + 1000] != -1)
            return dp[i][sum + 1000];
        int add = solve(i - 1, sum + nums[i], nums, target, dp);
        int sub = solve(i - 1, sum - nums[i], nums, target, dp);
        return dp[i][sum + 1000] = add + sub;

    }

    int findTargetSumWays(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, -1)); 
        return solve(n - 1, 0, nums, target, dp);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << sol.findTargetSumWays(nums, target) << endl;
    return 0;
}   