#include <bits/stdc++.h>
#include <string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> mpp = {
            "",    
            "",    
            "abc",
            "def", 
            "ghi",
            "jkl",
            "mno", 
            "pqrs",
            "tuv", 
            "wxyz"
        };

        vector<string> result;
        string current = "";

        helper(0, digits, current, result, mpp);
        return result;
    }

private:
    void helper(int index, string &digits, string &current, vector<string> &result, vector<string> &mpp) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        int find = digits[index] - '0';
        string letters = mpp[find];
        for (char ch : letters) {
            current.push_back(ch);
            helper(index + 1, digits, current, result, mpp);
            current.pop_back();
        }
    }
};

int main() {
    Solution s;
    string digits = "23"; 
    vector<string> ans = s.letterCombinations(digits);
    for (string str : ans)
        cout << str << " ";
    cout << endl;
    return 0;
}
