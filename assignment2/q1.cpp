#include <bits/stdc++.h>
#include <string>

using namespace std;

void solve(int n, int ones, int zeros, string output) {
    if (output.size() == n) {
        cout << output << endl;
        return;
    }
    solve(n, ones + 1, zeros, output + "1");
    if (ones > zeros)
        solve(n, ones, zeros + 1, output + "0");
}

int main() {
    int n;
    cin >> n;
    solve(n, 0, 0, "");
    return 0;
}
