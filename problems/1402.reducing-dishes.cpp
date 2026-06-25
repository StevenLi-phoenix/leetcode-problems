// @leetcode id=1402 questionId=1503 slug=reducing-dishes lang=cpp site=leetcode.com title="Reducing Dishes"
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int total = 0, sum = 0;
        // Add dishes greedily from highest to lowest
        // When we add dish i (0-indexed), it gets coefficient = 1, previous dishes get +1
        // Adding dish i increases total by (sum + satisfaction[i])
        for (int s : satisfaction) {
            if (sum + s > 0) {
                sum += s;
                total += sum;
            } else {
                break; // Since sorted in desc order, no more beneficial
            }
        }
        return total;
    }
};
