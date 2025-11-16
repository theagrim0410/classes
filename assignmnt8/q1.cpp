#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int maxLen = 0 ;
     int solve(string &s1, string &s2, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 || j == 0)
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = 1 +  solve(s1, s2, i - 1, j - 1,dp);
            maxLen = max(maxLen, dp[i][j]);
        }
        else dp[i][j] = 0;
        solve(s1, s2, i - 1, j,dp);
        solve(s1, s2, i, j - 1,dp);

        return dp[i][j];
    }
    
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        // solve(s1, s2, n , m, dp);
        // return maxLen;
        int maxlen = 0;
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=m ; j++){
                if(s1[i-1] == s2[j-1]){
                  dp[i][j] = 1+ dp[i-1][j-1];
                  maxlen = max(maxlen, dp[i][j]);
                } 
                else dp[i][j] = 0;
            }
        }
        
        return maxlen;
    }
    
};

int main() {
    string s1 = "abcdxyz";
    string s2 = "xyzabcd";
    Solution obj;
    cout << obj.longestCommonSubstr(s1, s2) << endl;
    return 0;
}
