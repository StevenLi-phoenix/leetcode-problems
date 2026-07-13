// @leetcode id=3923 questionId=4133 slug=minimum-generations-to-target-point lang=cpp site=leetcode.com title="Minimum Generations to Target Point"
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        // Coordinates are bounded to 0..6, so the whole space is only
        // 7^3 = 343 distinct points; simulate generations (each pair from
        // the full accumulated set so far) until the target appears or the
        // set stops growing.
        auto encode = [](int x, int y, int z) { return x * 49 + y * 7 + z; };

        vector<char> present(343, 0);
        vector<array<int, 3>> all;
        for (auto& p : points) {
            int e = encode(p[0], p[1], p[2]);
            if (!present[e]) {
                present[e] = 1;
                all.push_back({p[0], p[1], p[2]});
            }
        }

        int targetCode = encode(target[0], target[1], target[2]);
        if (present[targetCode]) return 0;

        int gen = 0;
        while (true) {
            gen++;
            vector<array<int, 3>> fresh;
            int n = all.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int x = (all[i][0] + all[j][0]) / 2;
                    int y = (all[i][1] + all[j][1]) / 2;
                    int z = (all[i][2] + all[j][2]) / 2;
                    int e = encode(x, y, z);
                    if (!present[e]) {
                        present[e] = 1;
                        fresh.push_back({x, y, z});
                    }
                }
            }
            if (fresh.empty()) return -1;
            if (present[targetCode]) return gen;
            for (auto& p : fresh) all.push_back(p);
        }
    }
};
