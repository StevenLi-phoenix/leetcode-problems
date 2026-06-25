// @leetcode id=2917 questionId=3183 slug=find-the-k-or-of-an-array lang=cpp site=leetcode.com title="Find the K-or of an Array"
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int result = 0;

        for (int bit = 0; bit < 31; bit++) {
            int count = 0;
            for (int num : nums) {
                if (num & (1 << bit)) {
                    count++;
                }
            }

            if (count >= k) {
                result |= (1 << bit);
            }
        }

        return result;
    }
};
