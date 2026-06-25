// @leetcode id=528 questionId=912 slug=random-pick-with-weight lang=cpp site=leetcode.com title="Random Pick with Weight"
class Solution {
    vector<int> prefix;
    int total;
public:
    Solution(vector<int>& w) {
        prefix.resize(w.size());
        prefix[0] = w[0];
        for (int i = 1; i < (int)w.size(); i++) {
            prefix[i] = prefix[i-1] + w[i];
        }
        total = prefix.back();
    }
    
    int pickIndex() {
        int target = rand() % total + 1;
        // Binary search for first index where prefix[i] >= target
        int lo = 0, hi = (int)prefix.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (prefix[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
