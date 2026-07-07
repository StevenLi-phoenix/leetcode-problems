// @leetcode id=1385 questionId=1486 slug=find-the-distance-value-between-two-arrays lang=cpp site=leetcode.com title="Find the Distance Value Between Two Arrays"
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for (int a : arr1) {
            bool ok = true;
            for (int b : arr2) {
                if (abs(a - b) <= d) { ok = false; break; }
            }
            if (ok) ++count;
        }
        return count;
    }
};
