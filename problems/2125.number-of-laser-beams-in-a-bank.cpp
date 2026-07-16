// @leetcode id=2125 questionId=2244 slug=number-of-laser-beams-in-a-bank lang=cpp site=leetcode.com title="Number of Laser Beams in a Bank"
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long total = 0;
        int prev = 0;
        for (auto& row : bank) {
            int cnt = count(row.begin(), row.end(), '1');
            if (cnt == 0) continue;
            total += (long long)prev * cnt;
            prev = cnt;
        }
        return (int)total;
    }
};
