// @leetcode id=2350 questionId=2435 slug=shortest-impossible-sequence-of-rolls lang=cpp site=leetcode.com title="Shortest Impossible Sequence of Rolls"
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int rounds = 0;
        unordered_set<int> seen;

        for (int r : rolls) {
            seen.insert(r);
            if ((int)seen.size() == k) {
                rounds++;
                seen.clear();
            }
        }

        return rounds + 1;
    }
};
