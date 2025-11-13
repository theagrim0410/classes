#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int solve(int i, int curr, vector<int>& nums, vector<vector<int>>&dp) {
        if (i < 0) {
            return curr == 0 ? 1 : 0;
        }
        
        if(dp[i][curr] != -1) return dp[i][curr];

        int take = 0;
        if (curr >= nums[i])
            take = solve(i - 1, curr - nums[i], nums,dp);
        int nottake = solve(i - 1, curr, nums,dp);
        return dp[i][curr] = take + nottake;
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        // vector<vector<int>>dp(n+1, vector<int>(target + 1 , -1));
        // return solve(n - 1, target, arr, dp);

        vector<vector<int>>dp(n+1, vector<int>(target + 1 , 0));
        
        for(int i=0;i<n;i++)dp[i][0]=1;
        
        if(target>=arr[0]) dp[0][arr[0]]+=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int take = (arr[i]<=j)? dp[i-1][j-arr[i]]:0;
                int nottake = dp[i-1][j];
                dp[i][j]=take +nottake;
            }
        }
        return dp[n-1][target];
    }
};


int main() {
    Solution sol;
    vector<int> nums = {5, 2, 3, 10, 6, 8};
    int target = 6;
    cout << sol.perfectSum(nums, target) << endl;
    return 0;
}