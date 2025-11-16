#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string solve(int i , int j , string& str1 , string& str2, vector<vector<string>>&dp){
        if(i == 0 ) return str2.substr(0,j);
        if(j == 0 ) return str1.substr(0,i);
        if(dp[i][j] != "#") return dp[i][j];
        if(str1[i-1] == str2[j-1]) return dp[i][j] = solve(i-1, j-1, str1, str2,dp) + str2[j-1];

        string take =  solve(i-1, j , str1 ,str2,dp) + str1[i-1];
        string nottake = solve(i,j-1,str1,str2,dp) +str2[j-1];

        return dp[i][j] = (take.length() < nottake.length()) ? take : nottake;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        // vector<vector<string>>dp(n+1, vector<string>(m+1, "#"));
        // return solve(n , m , str1 , str2, dp);
         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        //constructing scs using lcs n+m-l
        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
    
            else if (dp[i-1][j] > dp[i][j-1]) {
                ans.push_back(str1[i-1]);
                i--;
            } else {
                ans.push_back(str2[j-1]);
                j--;
            }
        }
        while (i > 0) {
            ans.push_back(str1[i-1]);
            i--;
        }
        while (j > 0) {
            ans.push_back(str2[j-1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};

int main() {
    string str1 = "abac";
    string str2 = "cab";
    Solution obj;
    cout << obj.shortestCommonSupersequence(str1, str2) << endl;
    return 0;
}