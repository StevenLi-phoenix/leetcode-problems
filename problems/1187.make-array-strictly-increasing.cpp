// @leetcode id=1187 questionId=1290 slug=make-array-strictly-increasing lang=cpp site=leetcode.com title="Make Array Strictly Increasing"
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        
        map<int, int> dp;
        dp[-1] = 0;
        
        for (int i = 0; i < arr1.size(); i++) {
            map<int, int> newDp;
            for (auto& [prev, ops] : dp) {
                // Option 1: Keep arr1[i]
                if (arr1[i] > prev) {
                    if (newDp.find(arr1[i]) == newDp.end()) {
                        newDp[arr1[i]] = ops;
                    } else {
                        newDp[arr1[i]] = min(newDp[arr1[i]], ops);
                    }
                }
                
                // Option 2: Replace with value from arr2
                auto it = upper_bound(arr2.begin(), arr2.end(), prev);
                if (it != arr2.end()) {
                    int val = *it;
                    if (newDp.find(val) == newDp.end()) {
                        newDp[val] = ops + 1;
                    } else {
                        newDp[val] = min(newDp[val], ops + 1);
                    }
                }
            }
            dp = newDp;
        }
        
        if (dp.empty()) return -1;
        int ans = INT_MAX;
        for (auto& [val, ops] : dp) {
            ans = min(ans, ops);
        }
        return ans;
    }
};
