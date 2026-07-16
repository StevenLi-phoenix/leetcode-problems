// @leetcode id=3265 questionId=3534 slug=count-almost-equal-pairs-i lang=cpp site=leetcode.com title="Count Almost Equal Pairs I"
class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (almostEqual(nums[i], nums[j])) count++;
            }
        }
        return count;
    }

private:
    bool almostEqual(int x, int y) {
        string a = to_string(x), b = to_string(y);
        int len = max(a.size(), b.size());
        a = string(len - a.size(), '0') + a;
        b = string(len - b.size(), '0') + b;

        vector<int> diffs;
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) diffs.push_back(i);
        }
        if (diffs.empty()) return true;
        if (diffs.size() == 2) {
            int i = diffs[0], j = diffs[1];
            return a[i] == b[j] && a[j] == b[i];
        }
        return false;
    }
};
