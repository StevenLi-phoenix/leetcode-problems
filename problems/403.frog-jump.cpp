// @leetcode id=403 questionId=403 slug=frog-jump lang=cpp site=leetcode.com title="Frog Jump"
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> jumps;
        for (int s : stones) jumps[s] = {};
        jumps[0].insert(0);

        for (int s : stones) {
            for (int k : jumps[s]) {
                for (int nk = k - 1; nk <= k + 1; nk++) {
                    if (nk <= 0) continue;
                    int next = s + nk;
                    if (jumps.count(next)) jumps[next].insert(nk);
                }
            }
        }
        return !jumps[stones[n - 1]].empty();
    }
};
