// @leetcode id=2200 questionId=2320 slug=find-all-k-distant-indices-in-an-array lang=cpp site=leetcode.com title="Find All K-Distant Indices in an Array"
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> valid(n, false);
        
        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                int lo = max(0, j - k);
                int hi = min(n - 1, j + k);
                for (int i = lo; i <= hi; i++) {
                    valid[i] = true;
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (valid[i]) result.push_back(i);
        }
        return result;
    }
};
