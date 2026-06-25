// @leetcode id=2449 questionId=2539 slug=minimum-number-of-operations-to-make-arrays-similar lang=cpp site=leetcode.com title="Minimum Number of Operations to Make Arrays Similar"
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> nums_even, nums_odd, target_even, target_odd;

        for (int x : nums) {
            if (x % 2 == 0) nums_even.push_back(x);
            else nums_odd.push_back(x);
        }

        for (int x : target) {
            if (x % 2 == 0) target_even.push_back(x);
            else target_odd.push_back(x);
        }

        sort(nums_even.begin(), nums_even.end());
        sort(nums_odd.begin(), nums_odd.end());
        sort(target_even.begin(), target_even.end());
        sort(target_odd.begin(), target_odd.end());

        long long ops = 0;

        for (int i = 0; i < nums_even.size(); i++) {
            ops += abs(nums_even[i] - target_even[i]);
        }

        for (int i = 0; i < nums_odd.size(); i++) {
            ops += abs(nums_odd[i] - target_odd[i]);
        }

        return ops / 4;
    }
};
