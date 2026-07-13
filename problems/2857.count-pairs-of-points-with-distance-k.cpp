// @leetcode id=2857 questionId=2953 slug=count-pairs-of-points-with-distance-k lang=cpp site=leetcode.com title="Count Pairs of Points With Distance k"
class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        // For each new point, try every way k splits into (a, b) with
        // a+b=k, and look up how many previously-seen points are exactly
        // that XOR-distance away (x^a, y^b), then add the current point.
        unordered_map<long long, int> seen;
        long long count = 0;

        for (auto& p : coordinates) {
            int x = p[0], y = p[1];
            for (int a = 0; a <= k; a++) {
                int b = k - a;
                int tx = x ^ a, ty = y ^ b;
                long long key = (long long)tx * 2000001LL + ty;
                auto it = seen.find(key);
                if (it != seen.end()) count += it->second;
            }
            long long selfKey = (long long)x * 2000001LL + y;
            seen[selfKey]++;
        }
        return (int)count;
    }
};
