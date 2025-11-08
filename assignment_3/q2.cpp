#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> res;
    void solve(string s , int i){
        if(i == s.length()){
            ans.push_back(res);
            return;
        }

        for(int j = i+1;j<=s.length();j++){
            if(check(s,i,j-1)){
                res.push_back(s.substr(i,j-i));
                solve(s,j);
                res.pop_back();
            }
        }
    }

    bool check(string s , int i , int j){
        while(i<j){
            if(s[i++ ]!= s[j--]) return false;
        }

        return true;
    }

    vector<vector<string>> partition(string s) {
        solve(s,0);
        return ans ;
    }
};

int main(){
    Solution sol;
    string s = "aab";
    vector<vector<string>> ans = sol.partition(s);
    
    for(auto& ele : ans){
        cout << "[ ";
        for(string str : ele){
            cout << str << ",";
        }
        cout << "]," << endl;
    }
    return 0;
}