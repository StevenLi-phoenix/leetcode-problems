// @leetcode id=2122 questionId=2241 slug=recover-the-original-array lang=cpp site=leetcode.com title="Recover the Original Array"
class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int m = nums.size(); // m = 2n
        int n = m / 2;
        sort(nums.begin(), nums.end());
        
        // nums[0] is always in lower array
        // Try each possible pair for nums[0]: nums[0] is lower, nums[j] is higher
        // 2k = nums[j] - nums[0] must be even and positive
        for (int j = 1; j < m; j++) {
            int diff = nums[j] - nums[0];
            if (diff == 0 || diff % 2 != 0) continue;
            int twoK = diff;
            
            // Try to pair elements using multiset
            multiset<int> ms(nums.begin(), nums.end());
            vector<int> arr;
            bool valid = true;
            
            while (!ms.empty()) {
                // Take the smallest available as lower
                int lo = *ms.begin();
                ms.erase(ms.begin());
                int hi = lo + twoK;
                auto it = ms.find(hi);
                if (it == ms.end()) {
                    valid = false;
                    break;
                }
                ms.erase(it);
                arr.push_back(lo + twoK / 2);
            }
            
            if (valid && (int)arr.size() == n) {
                return arr;
            }
        }
        
        return {};
    }
};
