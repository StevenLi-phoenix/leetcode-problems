// @leetcode id=1985 questionId=2113 slug=find-the-kth-largest-integer-in-the-array lang=cpp site=leetcode.com title="Find the Kth Largest Integer in the Array"
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            if (a.size() != b.size()) return a.size() > b.size();
            return a > b;
        });
        return nums[k - 1];
    }
};
