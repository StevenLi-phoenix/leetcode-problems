// @leetcode id=2094 questionId=2215 slug=finding-3-digit-even-numbers lang=cpp site=leetcode.com title="Finding 3-Digit Even Numbers"
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int count[10] = {0};
        for (int d : digits) count[d]++;

        vector<int> result;
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100, d2 = (num / 10) % 10, d3 = num % 10;
            int need[10] = {0};
            need[d1]++;
            need[d2]++;
            need[d3]++;

            bool ok = true;
            for (int d = 0; d < 10; d++) {
                if (need[d] > count[d]) { ok = false; break; }
            }
            if (ok) result.push_back(num);
        }
        return result;
    }
};
