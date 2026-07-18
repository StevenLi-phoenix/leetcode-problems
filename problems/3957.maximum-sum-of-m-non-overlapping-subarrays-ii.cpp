// @leetcode id=3957 questionId=4125 slug=maximum-sum-of-m-non-overlapping-subarrays-ii lang=cpp site=leetcode.com title="Maximum Sum of M Non-Overlapping Subarrays II"
class Solution {
public:
    // returns {bestValue, minCountAchievingBestValue} for the unconstrained
    // problem: max over any number of non-overlapping subarrays (length in [l,r])
    // of (sum - lambda * count)
    pair<long long,long long> solve(vector<long long>& prefix, int n, int l, int r, long long lambda) {
        vector<long long> dpVal(n + 1);
        vector<long long> dpCnt(n + 1);
        dpVal[0] = 0;
        dpCnt[0] = 0;

        deque<int> dq; // stores index j, monotonic by (dpVal[j]-prefix[j]) desc, tie-break min dpCnt[j]

        for (int i = 1; i <= n; i++) {
            int jAvail = i - l;
            if (jAvail >= 0) {
                long long v = dpVal[jAvail] - prefix[jAvail];
                long long c = dpCnt[jAvail];
                while (!dq.empty()) {
                    int back = dq.back();
                    long long bv = dpVal[back] - prefix[back];
                    long long bc = dpCnt[back];
                    if (bv < v || (bv == v && bc >= c)) {
                        dq.pop_back();
                    } else {
                        break;
                    }
                }
                dq.push_back(jAvail);
            }

            int lowBound = i - r;
            while (!dq.empty() && dq.front() < lowBound) dq.pop_front();

            dpVal[i] = dpVal[i - 1];
            dpCnt[i] = dpCnt[i - 1];

            if (!dq.empty()) {
                int j = dq.front();
                long long candVal = dpVal[j] - prefix[j] + prefix[i] - lambda;
                long long candCnt = dpCnt[j] + 1;
                if (candVal > dpVal[i] || (candVal == dpVal[i] && candCnt < dpCnt[i])) {
                    dpVal[i] = candVal;
                    dpCnt[i] = candCnt;
                }
            }
        }

        return {dpVal[n], dpCnt[n]};
    }

    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        long long bestSingle = LLONG_MIN;
        {
            deque<int> dq;
            for (int end = l; end <= n; end++) {
                int newStart = end - l;
                while (!dq.empty() && prefix[dq.back()] >= prefix[newStart]) dq.pop_back();
                dq.push_back(newStart);
                int lowBound = end - r;
                while (!dq.empty() && dq.front() < lowBound) dq.pop_front();
                if (!dq.empty()) {
                    bestSingle = max(bestSingle, prefix[end] - prefix[dq.front()]);
                }
            }
        }

        auto zero = solve(prefix, n, l, r, 0);
        if (zero.second >= 1 && zero.second <= m) {
            return zero.first;
        }
        if (zero.second == 0) {
            return bestSingle;
        }

        long long lo = 0, hi = 200000000000LL;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            auto res = solve(prefix, n, l, r, mid);
            if (res.second <= m) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        auto res = solve(prefix, n, l, r, lo);
        return res.first + lo * m;
    }
};
