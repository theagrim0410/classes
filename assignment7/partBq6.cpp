#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
long long solve(vector<long long> &freq, long long i, long long end, vector<long long> &dp) {
    if (i > end) return 0;
    if (dp[i] != -1) return dp[i];
 
    long long include = freq[i] * i + solve(freq, i + 2, end, dp);
    long long exclude = solve(freq, i + 1, end, dp);
 
    return dp[i] = max(include, exclude);
}

long long function(vector<long long> &a) {
    long long mx = *max_element(a.begin(), a.end());
 
    vector<long long> freq(mx + 1, 0);
    for (long long num : a)
        freq[num]++;
 
    // vector<long long> dp(mx + 1, -1);
    // return solve(freq, 0, mx, dp);

    vector<long long> dp(mx + 1, 0);

    dp[0] = 0;
    if (mx >= 1) dp[1] = freq[1] * 1;
    for (long long i = 2; i <= mx; i++) {
        long long include = freq[i] * i + dp[i - 2];
        long long exclude = dp[i - 1];
        dp[i] = max(include, exclude);
    }
    return dp[mx];

}

int main() {
    long long n;
    cin >> n;
 
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    cout << function(a) << endl;
 
    return 0;
}