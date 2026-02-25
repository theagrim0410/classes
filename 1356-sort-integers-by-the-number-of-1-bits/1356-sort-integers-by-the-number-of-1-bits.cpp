class Solution {
public:
    int counting(int n) {
        int cnt = 0;
        while(n > 0) {
            cnt += (n & 1);
            n = n >> 1;
        }

        return cnt;
    }

    //and orerator return rightest bit and >> shifts the n by 1 right side

    vector<int> sortByBits(vector<int>& arr){
        map<int,multiset<int>>mpp;
        for(int i = 0 ; i < arr.size(); i++){
            int bit = counting(arr[i]);
            mpp[bit].insert(arr[i]);
        }
        vector<int> ans ;
        for(auto p : mpp){
            for(int val : p.second) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};