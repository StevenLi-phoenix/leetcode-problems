// @leetcode id=710 questionId=894 slug=random-pick-with-blacklist lang=cpp site=leetcode.com title="Random Pick with Blacklist"
class Solution {
public:
    int bound;
    unordered_map<int, int> remap;

    Solution(int n, vector<int>& blacklist) {
        bound = n - blacklist.size();
        unordered_set<int> blackSet(blacklist.begin(), blacklist.end());

        int next = bound;
        for (int b : blacklist) {
            if (b < bound) {
                while (blackSet.count(next)) next++;
                remap[b] = next;
                next++;
            }
        }
    }

    int pick() {
        int idx = rand() % bound;
        auto it = remap.find(idx);
        return it != remap.end() ? it->second : idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
