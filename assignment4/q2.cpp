#include <bits/stdc++.h>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<string> helper(string s, unordered_set<string>& st, int i, unordered_map<int, vector<string>>& temp) {
    if (temp.count(i)) return temp[i];
    if (i == s.size()) return {""}; 

    vector<string> ans;

    for (int end = i + 1; end <= s.size(); ++end) {
        string word = s.substr(i, end - i);
        if (st.count(word)) {
            vector<string> subList = helper(s, st, end, temp);
            for (string sub : subList) {
                string space = sub.empty() ? "" : " ";
                ans.push_back(word + space + sub);
            }
        }
    }

    return temp[i] = ans;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    unordered_map<int, vector<string>> temp;
    return helper(s, st, 0, temp);
}

int main() {
    string s = "agrimsaxena";
    vector<string> wordDict = {"ag", "rim", "s", "ax", "ena"};
    vector<string> ans = wordBreak(s, wordDict);

    for (string& ele : ans)
        cout << ele << endl;
    return 0;
}
