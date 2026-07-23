// @leetcode id=3842 questionId=4212 slug=toggle-light-bulbs lang=cpp site=leetcode.com title="Toggle Light Bulbs"
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int count[101] = {0};
        for (int b : bulbs) count[b]++;

        vector<int> result;
        for (int i = 1; i <= 100; i++) {
            if (count[i] % 2 == 1) result.push_back(i);
        }
        return result;
    }
};
