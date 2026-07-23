// @leetcode id=1013 questionId=1062 slug=partition-array-into-three-parts-with-equal-sum lang=cpp site=leetcode.com title="Partition Array Into Three Parts With Equal Sum"
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long long total = 0;
        for (int x : arr) total += x;
        if (total % 3 != 0) return false;

        long long target = total / 3;
        int n = arr.size();
        int parts = 0;
        long long running = 0;

        for (int i = 0; i < n; i++) {
            running += arr[i];
            if (running == target) {
                parts++;
                running = 0;
                if (parts == 2 && i < n - 1) return true;
            }
        }
        return false;
    }
};
