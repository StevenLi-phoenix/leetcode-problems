// @leetcode id=2164 questionId=2283 slug=sort-even-and-odd-indices-independently lang=cpp site=leetcode.com title="Sort Even and Odd Indices Independently"
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> evens, odds;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) evens.push_back(nums[i]);
            else odds.push_back(nums[i]);
        }

        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end(), greater<int>());

        vector<int> result(n);
        for (int i = 0, e = 0, o = 0; i < n; ++i) {
            result[i] = (i % 2 == 0) ? evens[e++] : odds[o++];
        }
        return result;
    }
};
