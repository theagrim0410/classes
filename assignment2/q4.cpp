#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(1, n, k, curr, ans);
        return ans;
    }

private:
    void helper(int start, int n, int k, vector<int>& curr, vector<vector<int>>& ans) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            helper(i + 1, n, k, curr, ans);
            curr.pop_back(); 
        }
    }
};

int main() {
    Solution s;
    int n = 4, k = 3;
    vector<vector<int>> arr = s.combine(n, k);
    for (auto &comb : arr) {
        for (int num : comb) cout << num << ",";
        cout << "\n";
    }

    return 0;
}
