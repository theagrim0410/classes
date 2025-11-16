#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool solve(int i , int j , string s , string p , vector<vector<int>>&dp){
        if (i == 0 && j == 0) return true;
        if (i > 0 && j == 0) return false;
        if (i == 0 && j > 0) {
            for (int k = 0; k < j; k++)
                if (p[k] != '*') return false;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1] == p[j-1] || p[j-1] == '?') return dp[i][j] = solve(i-1, j-1 , s,p,dp);
        if(p[j-1] == '*') return dp[i][j] = solve(i-1, j , s, p,dp) || solve(i,j-1,s,p,dp);

        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solve(n , m , s , p , dp);

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j-1] == s[i-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }

        return dp[n][m];
    }
};


int main(){
    Solution obj;
    string s = "aab";
    string p = "*ab?";
    if(obj.isMatch(s,p)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}