#include <bits/stdc++.h>
#include <string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> result;
    string current = "";
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
        helper(0, digits, mpp);
        return result;
    }
    
    void helper(int index, string &digits, vector<string>&mpp) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        int find = digits[index] - '0';
        string letters = mpp[find];
        for (char ch : letters) {
            current.push_back(ch);
            helper(index + 1, digits, mpp);
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
