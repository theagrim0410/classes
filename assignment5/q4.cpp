#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>&freq, int i , int end , vector<int>&dp){
    if(i > end) return 0;
    if(dp[i] != -1) return dp[i];
    int yes = freq[i] * i + solve(freq, i + 2, end, dp);
    int no = 0 + solve(freq, i + 1, end, dp);
    return dp[i] = max(yes, no);
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int mx = *max_element(a.begin(), a.end());

    vector<int> freq(mx + 1, 0);
    for (int num : a)
        freq[num]++;

    vector<int> dp(mx + 1, -1);
    cout << solve(freq, 0, mx, dp) << endl;

    return 0;
}