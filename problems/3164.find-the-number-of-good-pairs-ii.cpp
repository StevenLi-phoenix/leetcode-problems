// @leetcode id=3164 questionId=3444 slug=find-the-number-of-good-pairs-ii lang=cpp site=leetcode.com title="Find the Number of Good Pairs II"
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> freq2;
        for (int v : nums2) freq2[v]++;

        long long ans = 0;
        for (int num : nums1) {
            if (num % k != 0) continue;
            int m = num / k;
            for (long long d = 1; d * d <= m; d++) {
                if (m % d != 0) continue;
                auto it = freq2.find((int)d);
                if (it != freq2.end()) ans += it->second;
                long long d2 = m / d;
                if (d2 != d) {
                    auto it2 = freq2.find((int)d2);
                    if (it2 != freq2.end()) ans += it2->second;
                }
            }
        }
        return ans;
    }
};
