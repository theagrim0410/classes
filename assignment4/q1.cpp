#include <bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool helper(string s, unordered_set<string>& st, int start) {
    if (start == s.size()) return true;

    for (int end = start + 1; end <= s.size(); ++end) {
        string word = s.substr(start, end - start);
        if (st.count(word) && helper(s, st, end))
            return true; 
    }

    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    return helper(s, st, 0);
}

int main() {
    string s = "agrimsaxena";
    vector<string> wordDict = {"ag", "rim", "s", "ax", "ena"};
    cout << (wordBreak(s, wordDict) ? "true" : "false");
    return 0;
}
