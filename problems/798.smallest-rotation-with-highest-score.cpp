// @leetcode id=798 questionId=814 slug=smallest-rotation-with-highest-score lang=cpp site=leetcode.com title="Smallest Rotation with Highest Score"
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int v = nums[i];
            int start = (i + 1) % n;
            int end = ((i - v) % n + n) % n;

            if (start <= end) {
                diff[start]++;
                diff[end + 1]--;
            } else {
                diff[start]++;
                diff[n]--;
                diff[0]++;
                diff[end + 1]--;
            }
        }

        int bestK = 0;
        int bestScore = -1;
        int cur = 0;
        for (int k = 0; k < n; k++) {
            cur += diff[k];
            if (cur > bestScore) {
                bestScore = cur;
                bestK = k;
            }
        }

        return bestK;
    }
};
