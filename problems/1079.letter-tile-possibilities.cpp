// @leetcode id=1079 questionId=1160 slug=letter-tile-possibilities lang=cpp site=leetcode.com title="Letter Tile Possibilities"
class Solution {
public:
    int dfs(vector<int>& count) {
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) continue;
            count[i]--;
            total += 1 + dfs(count);
            count[i]++;
        }
        return total;
    }

    int numTilePossibilities(string tiles) {
        vector<int> count(26, 0);
        for (char c : tiles) count[c - 'A']++;
        return dfs(count);
    }
};
