// @leetcode id=1674 questionId=1793 slug=minimum-moves-to-make-array-complementary lang=cpp site=leetcode.com title="Minimum Moves to Make Array Complementary"
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2*limit+2, 0);

        for (int i = 0; i < n/2; i++){
            int a = nums[i];
            int b = nums[n-1-i];
            int lo = min(a, b) + 1;
            int hi = max(a, b) + limit;
            int sum = a + b;

            diff[lo]--;
            diff[hi+1]++;
            diff[sum]--;
            diff[sum+1]++;
        }

        int result = n;
        int current = 0;
        for (int i = 2; i <= 2*limit; i++){
            current += diff[i];
            result = min(result, n + current);
        }
        return result;
    }
};
