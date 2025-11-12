#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        if (i == m - 1 && j == n - 1)
            return dungeon[i][j] >= 0 ? 1 : 1 - dungeon[i][j];
        
        if (i >= m || j >= n) return INT_MAX;
        int right = solve(i, j + 1, dungeon);
        int down = solve(i + 1, j, dungeon);
        int next = min(right, down);
        int need = next - dungeon[i][j];

        return need <= 0 ? 1 : need;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        return solve(0, 0, dungeon);
    }
};

int main() {
    vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    Solution s;
    cout << s.calculateMinimumHP(dungeon);
}
