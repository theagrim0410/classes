#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int helper(const string &s, int i, int ans, int res) {
    if (i == s.size())
        return -res;
    if (s[i] == '(') ans++;
    else ans--;
    res = min(res, ans);
    return helper(s, i + 1, ans, res);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << helper(s, 0, 0, 0) << "\n";
    }
    return 0;
}
