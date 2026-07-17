// @leetcode id=2584 questionId=2647 slug=split-the-array-to-make-coprime-products lang=cpp site=leetcode.com title="Split the Array to Make Coprime Products"
class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        const int MAXV = 1000001;
        vector<int> spf(MAXV, 0);
        for (int i = 2; i < MAXV; i++) {
            if (spf[i] == 0) {
                for (long long j = i; j < MAXV; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }

        unordered_map<int, int> lastOcc;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 1) {
                int p = spf[x];
                lastOcc[p] = i;
                while (x % p == 0) x /= p;
            }
        }

        int runningMax = -1;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 1) {
                int p = spf[x];
                runningMax = max(runningMax, lastOcc[p]);
                while (x % p == 0) x /= p;
            }
            if (i < n - 1 && runningMax <= i) return i;
        }

        return -1;
    }
};
