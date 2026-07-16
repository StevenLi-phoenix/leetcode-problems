// @leetcode id=3551 questionId=3847 slug=minimum-swaps-to-sort-by-digit-sum lang=cpp site=leetcode.com title="Minimum Swaps to Sort by Digit Sum"
class Solution {
public:
    int digitSum(int x) {
        int s = 0;
        while (x > 0) { s += x % 10; x /= 10; }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            int sa = digitSum(nums[a]), sb = digitSum(nums[b]);
            if (sa != sb) return sa < sb;
            return nums[a] < nums[b];
        });

        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[idx[i]] = i;

        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || pos[i] == i) continue;
            int cycleLen = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = pos[j];
                cycleLen++;
            }
            swaps += cycleLen - 1;
        }
        return swaps;
    }
};
