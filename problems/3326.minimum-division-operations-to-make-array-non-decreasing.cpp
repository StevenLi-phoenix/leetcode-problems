// @leetcode id=3326 questionId=3607 slug=minimum-division-operations-to-make-array-non-decreasing lang=cpp site=leetcode.com title="Minimum Division Operations to Make Array Non Decreasing"
class Solution {
public:
    int minOperations(vector<int>& nums) {
        static const vector<int> spf = buildSpf();

        int n = nums.size();
        long long ops = 0;
        int next = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            int x = nums[i];
            if (x <= next) {
                next = x;
                continue;
            }
            int s = spf[x];
            if (s == x || s > next) return -1;
            ops++;
            next = s;
        }
        return (int)ops;
    }

private:
    static vector<int> buildSpf() {
        const int MAXV = 1000001;
        vector<int> spf(MAXV, 0);
        for (int i = 2; i < MAXV; i++) {
            if (spf[i] == 0) {
                for (long long j = i; j < MAXV; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }
        return spf;
    }
};
