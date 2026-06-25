// @leetcode id=781 questionId=797 slug=rabbits-in-forest lang=cpp site=leetcode.com title="Rabbits in Forest"
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for (int a : answers) freq[a]++;
        int total = 0;
        for (auto& [k, cnt] : freq) {
            // k+1 rabbits can share same color
            // Need ceil(cnt / (k+1)) groups, each with k+1 rabbits
            int groups = (cnt + k) / (k + 1);
            total += groups * (k + 1);
        }
        return total;
    }
};
