// @leetcode id=3886 questionId=4257 slug=sum-of-sortable-integers lang=cpp site=leetcode.com title="Sum of Sortable Integers"
class Solution {
public:
    bool isRotation(vector<int>& nums, vector<int>& target, int start, int k) {
        vector<int> fail(k, 0);
        for (int i = 1; i < k; i++) {
            int j = fail[i - 1];
            while (j > 0 && target[start + i] != target[start + j]) j = fail[j - 1];
            if (target[start + i] == target[start + j]) j++;
            fail[i] = j;
        }

        int j = 0;
        int textLen = 2 * k - 1;
        for (int i = 0; i < textLen; i++) {
            int idx = start + (i % k);
            int val = nums[idx];
            while (j > 0 && val != target[start + j]) j = fail[j - 1];
            if (val == target[start + j]) j++;
            if (j == k) return true;
        }
        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> target = nums;
        sort(target.begin(), target.end());

        long long answer = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            bool ok = true;
            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, target, start, k)) { ok = false; break; }
            }
            if (ok) answer += k;
        }
        return (int)answer;
    }
};
