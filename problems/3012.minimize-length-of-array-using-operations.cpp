// @leetcode id=3012 questionId=3244 slug=minimize-length-of-array-using-operations lang=cpp site=leetcode.com title="Minimize Length of Array Using Operations"
class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int m = *min_element(nums.begin(), nums.end());

        bool allDivisible = true;
        int cnt = 0;
        for (int x : nums) {
            if (x % m != 0) allDivisible = false;
            if (x == m) cnt++;
        }

        if (!allDivisible) return 1;
        return (cnt + 1) / 2;
    }
};
