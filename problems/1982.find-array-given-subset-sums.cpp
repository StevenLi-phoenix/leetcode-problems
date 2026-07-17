// @leetcode id=1982 questionId=2109 slug=find-array-given-subset-sums lang=cpp site=leetcode.com title="Find Array Given Subset Sums"
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        multiset<int> current(sums.begin(), sums.end());
        vector<int> answer;

        for (int step = 0; step < n; step++) {
            vector<int> sorted(current.begin(), current.end());
            int diff = sorted[1] - sorted[0];

            multiset<int> group0, group1;
            multiset<int> pool = current;

            for (int v : sorted) {
                if (pool.find(v) == pool.end()) continue;
                pool.erase(pool.find(v));
                int partner = v + diff;
                auto it = pool.find(partner);
                if (it == pool.end()) continue;
                pool.erase(it);
                group0.insert(v);
                group1.insert(partner);
            }

            if (group0.find(0) != group0.end()) {
                answer.push_back(diff);
                current = group0;
            } else {
                answer.push_back(-diff);
                current = group1;
            }
        }

        return answer;
    }
};
