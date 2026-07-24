// @leetcode id=1313 questionId=1241 slug=decompress-run-length-encoded-list lang=cpp site=leetcode.com title="Decompress Run-Length Encoded List"
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i + 1 < (int)nums.size(); i += 2) {
            int freq = nums[i], val = nums[i + 1];
            for (int j = 0; j < freq; j++) result.push_back(val);
        }
        return result;
    }
};
