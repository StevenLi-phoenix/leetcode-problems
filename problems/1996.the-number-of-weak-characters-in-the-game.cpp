// @leetcode id=1996 questionId=2123 slug=the-number-of-weak-characters-in-the-game lang=cpp site=leetcode.com title="The Number of Weak Characters in the Game"
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // Sort by attack descending, defense ascending for same attack
        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });
        
        int maxDef = 0, result = 0;
        for (auto& p : properties) {
            if (p[1] < maxDef) result++;
            maxDef = max(maxDef, p[1]);
        }
        return result;
    }
};
