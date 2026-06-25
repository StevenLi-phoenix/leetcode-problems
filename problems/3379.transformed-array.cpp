// @leetcode id=3379 questionId=3651 slug=transformed-array lang=cpp site=leetcode.com title="Transformed Array"
class Solution {
    public:
    vector<int> constructTransformedArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
    int j = ((i + nums[i]) % n + n) % n;
    res[i] = nums[j];
    }
    return res;
    }
    };
