#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int helper(int a , int b){
        if(a == -1 || b ==-1) return 0;
        return abs(a/6 - b/6) + abs(a%6 - b%6);
    }
    int solve(string word , int i , int f1 , int f2, vector<vector<vector<int>>> &dp){
        if (i == word.size()) return 0;
        int curr = word[i] - 'A';
        if(dp[i][f1+1][f2+1] != -1) return dp[i][f1+1][f2+1]; 
        int use1 = helper(f1, curr) + solve(word, i + 1, curr, f2,dp);
        int use2 = helper(f2, curr) + solve(word, i + 1, f1, curr,dp);
        return dp[i][f1+1][f2+1] = min(use1, use2);
    }

    int minimumDistance(string word) {
        int n = word.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(27, vector<int>(27, -1)));
        return solve(word, 0, -1 , -1,dp);
    }
};

int main(){
    Solution sol;
    string word = "APPLE";
    cout << sol.minimumDistance(word) << endl; 
    return 0;
}