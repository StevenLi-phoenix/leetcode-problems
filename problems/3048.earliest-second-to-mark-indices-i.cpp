// @leetcode id=3048 questionId=3292 slug=earliest-second-to-mark-indices-i lang=cpp site=leetcode.com title="Earliest Second to Mark Indices I"
class Solution {
public:
    int n_, m_;

    bool feasible(int T, vector<int>& nums, vector<int>& changeIndices) {
        vector<int> lastOcc(n_ + 1, -1);
        for (int s = 1; s <= T; s++) {
            lastOcc[changeIndices[s - 1]] = s;
        }
        for (int i = 1; i <= n_; i++) {
            if (lastOcc[i] == -1) return false;
        }

        vector<pair<int, long long>> items;
        for (int i = 1; i <= n_; i++) {
            items.push_back({lastOcc[i], (long long)nums[i - 1]});
        }
        sort(items.begin(), items.end());

        long long cumCount = 0, cumNeeded = 0;
        for (auto& [t, need] : items) {
            cumCount++;
            cumNeeded += need;
            if (cumNeeded > (long long)t - cumCount) return false;
        }
        return true;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        n_ = nums.size();
        m_ = changeIndices.size();
        int lo = n_, hi = m_;
        int result = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(mid, nums, changeIndices)) {
                result = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return result;
    }
};
