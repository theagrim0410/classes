#include <bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> arr(26, 0);
        for (char c : tiles) arr[c - 'A']++;
        return helper(arr);
    }

private:
    int helper(vector<int>& arr) {
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i] == 0) continue;
            total++;
            arr[i]--;
            total += helper(arr);
            arr[i]++;
        }
        return total;
    }
};

int main() {
    Solution s;
    string tiles = "AABA";
    cout <<  s.numTilePossibilities(tiles) << endl;
    return 0;
}
