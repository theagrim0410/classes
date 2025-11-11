#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long solve(int x, vector<long long>& sum) {
    if (x == 0) return 0;
    if (x == 1) return sum[1];

    return max(solve(x - 1, sum), solve(x - 2, sum) + sum[x]);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int mx = *max_element(a.begin(), a.end());

    vector<long long> freq(mx + 1, 0), sum(mx + 1, 0);
    for (int num : a)
        freq[num]++;

    for (int i = 1; i <= mx; i++)
        sum[i] = 1LL * i * freq[i];
    cout << solve(mx, sum) << endl;
}
