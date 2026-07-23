// @leetcode id=3477 questionId=3790 slug=fruits-into-baskets-ii lang=cpp site=leetcode.com title="Fruits Into Baskets II"
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool> used(baskets.size(), false);
        int unplaced = 0;

        for (int f : fruits) {
            bool placed = false;
            for (int j = 0; j < (int)baskets.size(); j++) {
                if (!used[j] && baskets[j] >= f) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) unplaced++;
        }
        return unplaced;
    }
};
