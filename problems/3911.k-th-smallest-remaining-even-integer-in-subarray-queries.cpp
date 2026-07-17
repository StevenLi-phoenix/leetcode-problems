// @leetcode id=3911 questionId=4287 slug=k-th-smallest-remaining-even-integer-in-subarray-queries lang=cpp site=leetcode.com title="K-th Smallest Remaining Even Integer in Subarray Queries"
class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> evenPrefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            evenPrefix[i + 1] = evenPrefix[i] + (nums[i] % 2 == 0 ? 1 : 0);
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long k = q[2];

            auto countEvenUpTo = [&](long long V) -> long long {
                int posV = upper_bound(nums.begin(), nums.end(), V) - nums.begin();
                int hi = min(r, posV - 1);
                if (hi < l) return 0;
                return evenPrefix[hi + 1] - evenPrefix[l];
            };

            long long lo = 1, hi = k + (long long)(r - l + 1);
            while (lo < hi) {
                long long m = lo + (hi - lo) / 2;
                long long cnt = countEvenUpTo(2 * m);
                if (m - cnt >= k) hi = m;
                else lo = m + 1;
            }

            answer.push_back((int)(2 * lo));
        }

        return answer;
    }
};
