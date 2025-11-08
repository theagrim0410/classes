#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    void solve(int j , vector<int>&nums){
        if(j == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>st; 
        for (int i = j; i < nums.size(); i++) {
            if (st.count(nums[i])) continue;
            st.insert(nums[i]);
            swap(nums[j],nums[i]);
            solve(j+1,nums);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(0,nums);
        return ans;      
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,2};
    vector<vector<int>> ans = sol.permuteUnique(nums);
    
    for(auto& ele : ans){
        cout << "[ ";
        for(int num : ele){
            cout << num << ",";
        }
        cout << "]," << endl;
    }
    return 0;
}