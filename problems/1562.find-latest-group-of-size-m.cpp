// @leetcode id=1562 questionId=1684 slug=find-latest-group-of-size-m lang=cpp site=leetcode.com title="Find Latest Group of Size M"
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<int> length(n + 2, 0);
        vector<int> countOfLength(n + 1, 0);
        int result = -1;

        for (int step = 1; step <= n; step++) {
            int pos = arr[step - 1];
            int leftLen = length[pos - 1];
            int rightLen = length[pos + 1];
            int newLen = leftLen + rightLen + 1;

            length[pos] = newLen;
            length[pos - leftLen] = newLen;
            length[pos + rightLen] = newLen;

            countOfLength[leftLen]--;
            countOfLength[rightLen]--;
            countOfLength[newLen]++;

            if (countOfLength[m] > 0) result = step;
        }
        return result;
    }
};
