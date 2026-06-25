// @leetcode id=3524 questionId=3831 slug=find-x-value-of-array-i lang=cpp site=leetcode.com title="Find X Value of Array I"
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);
        
        // cnt[r] = number of left endpoints i such that product[i..j] % k == r
        // We iterate j from 0 to n-1
        // When we start j, we first add the single element nums[j] % k
        // Then for each existing left endpoint i < j, product[i..j] = product[i..j-1] * nums[j]
        
        vector<long long> cnt(k, 0);
        
        for (int j = 0; j < n; j++) {
            int nj = nums[j] % k;
            
            // Update existing counts: multiply each product by nums[j]
            vector<long long> new_cnt(k, 0);
            for (int r = 0; r < k; r++) {
                if (cnt[r] > 0) {
                    new_cnt[(r * nj) % k] += cnt[r];
                }
            }
            // Add new left endpoint starting at j
            new_cnt[nj]++;
            
            cnt = new_cnt;
            
            // Add counts to result
            for (int r = 0; r < k; r++) {
                result[r] += cnt[r];
            }
        }
        
        return result;
    }
};
