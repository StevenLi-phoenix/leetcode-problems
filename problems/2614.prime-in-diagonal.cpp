// @leetcode id=2614 questionId=2722 slug=prime-in-diagonal lang=cpp site=leetcode.com title="Prime In Diagonal"
class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int best = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i][i])) best = max(best, nums[i][i]);
            if (isPrime(nums[i][n - 1 - i])) best = max(best, nums[i][n - 1 - i]);
        }
        return best;
    }

private:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int d = 2; (long long)d * d <= x; d++) {
            if (x % d == 0) return false;
        }
        return true;
    }
};
