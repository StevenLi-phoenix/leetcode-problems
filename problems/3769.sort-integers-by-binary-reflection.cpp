// @leetcode id=3769 questionId=4150 slug=sort-integers-by-binary-reflection lang=cpp site=leetcode.com title="Sort Integers by Binary Reflection"
class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        auto binaryReflection = [](int n) {
            int result = 0;
            while (n > 0) {
                result = result * 2 + (n & 1);
                n >>= 1;
            }
            return result;
        };

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int reflectA = binaryReflection(a);
            int reflectB = binaryReflection(b);
            if (reflectA != reflectB) {
                return reflectA < reflectB;
            }
            return a < b;
        });

        return nums;
    }
};
