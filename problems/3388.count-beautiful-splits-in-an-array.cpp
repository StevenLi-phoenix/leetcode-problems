// @leetcode id=3388 questionId=3686 slug=count-beautiful-splits-in-an-array lang=cpp site=leetcode.com title="Count Beautiful Splits in an Array"
class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        size_t stride = n + 1;
        vector<int16_t> lcp(stride * stride, 0);
        auto idx = [&](int a, int b) -> size_t { return (size_t)a * stride + b; };

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (nums[i] == nums[j]) {
                    lcp[idx(i, j)] = lcp[idx(i + 1, j + 1)] + 1;
                } else {
                    lcp[idx(i, j)] = 0;
                }
            }
        }

        long long count = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int len1 = i, len2 = j - i, len3 = n - j;
                bool condA = (len1 <= len2) && (lcp[idx(0, i)] >= len1);
                bool condB = (len2 <= len3) && (lcp[idx(i, j)] >= len2);
                if (condA || condB) count++;
            }
        }

        return (int)count;
    }
};
