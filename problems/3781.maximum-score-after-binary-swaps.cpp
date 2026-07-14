// @leetcode id=3781 questionId=4130 slug=maximum-score-after-binary-swaps lang=cpp site=leetcode.com title="Maximum Score After Binary Swaps"
class Solution {
public:
    vector<int> parent_;
    int find(int x) {
        while (parent_[x] != x) {
            parent_[x] = parent_[parent_[x]];
            x = parent_[x];
        }
        return x;
    }

    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        vector<int> ones; // sorted positions of '1' (already ascending)
        for (int i = 0; i < n; i++) if (s[i] == '1') ones.push_back(i);
        int m = ones.size();
        if (m == 0) return 0;

        // DSU over job indices 0..m (1-indexed jobs 1..m by increasing
        // deadline; index m is the "no available job" sentinel).
        parent_.resize(m + 2);
        for (int i = 0; i <= m + 1; i++) parent_[i] = i;

        vector<int> slotOrder(n);
        for (int i = 0; i < n; i++) slotOrder[i] = i;
        sort(slotOrder.begin(), slotOrder.end(), [&](int a, int b) {
            return nums[a] > nums[b];
        });

        long long answer = 0;
        int assigned = 0;
        for (int s_pos : slotOrder) {
            if (assigned == m) break;
            // Smallest job (1-indexed among 1..m) whose deadline >= s_pos.
            int lo = lower_bound(ones.begin(), ones.end(), s_pos) - ones.begin(); // 0-indexed job
            if (lo >= m) continue; // no job has a deadline that large
            int avail = find(lo + 1); // DSU uses 1-indexed jobs, 0 is unused sentinel start
            if (avail <= m) {
                answer += nums[s_pos];
                assigned++;
                parent_[avail] = avail + 1;
            }
        }
        return answer;
    }
};
