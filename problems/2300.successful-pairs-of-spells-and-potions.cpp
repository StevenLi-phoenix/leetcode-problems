// @leetcode id=2300 questionId=2392 slug=successful-pairs-of-spells-and-potions lang=cpp site=leetcode.com title="Successful Pairs of Spells and Potions"
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> result;
        for (int spell : spells) {
            long long need = (success + spell - 1) / spell;
            int lo = 0, hi = m;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if ((long long)potions[mid] >= need) hi = mid;
                else lo = mid + 1;
            }
            result.push_back(m - lo);
        }
        return result;
    }
};
