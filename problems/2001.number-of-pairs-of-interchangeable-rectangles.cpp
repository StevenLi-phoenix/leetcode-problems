// @leetcode id=2001 questionId=2129 slug=number-of-pairs-of-interchangeable-rectangles lang=cpp site=leetcode.com title="Number of Pairs of Interchangeable Rectangles"
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<long long, long long> count;
        long long ans = 0;
        for (auto& r : rectangles) {
            int w = r[0], h = r[1];
            int g = gcd(w, h);
            w /= g; h /= g;
            long long key = (long long)w * 100001 + h;
            ans += count[key]++;
        }
        return ans;
    }
};
