// @leetcode id=765 questionId=770 slug=couples-holding-hands lang=cpp site=leetcode.com title="Couples Holding Hands"
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[row[i]] = i;

        int swaps = 0;
        for (int i = 0; i < n; i += 2) {
            int a = row[i];
            int partner = (a % 2 == 0) ? a + 1 : a - 1;
            if (row[i + 1] != partner) {
                int j = pos[partner];
                swap(row[i + 1], row[j]);
                pos[row[j]] = j;
                pos[row[i + 1]] = i + 1;
                swaps++;
            }
        }
        return swaps;
    }
};
