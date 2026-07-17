// @leetcode id=2106 questionId=2229 slug=maximum-fruits-harvested-after-at-most-k-steps lang=cpp site=leetcode.com title="Maximum Fruits Harvested After at Most K Steps"
class Solution {
public:
    long long cost(int l, int r, int startPos) {
        if (r <= startPos) return startPos - l;
        if (l >= startPos) return r - startPos;
        long long goRightFirst = (long long)2 * (r - startPos) + (startPos - l);
        long long goLeftFirst = (long long)2 * (startPos - l) + (r - startPos);
        return min(goRightFirst, goLeftFirst);
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + fruits[i][1];

        long long answer = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            while (i < j && cost(fruits[i][0], fruits[j][0], startPos) > k) i++;
            if (cost(fruits[i][0], fruits[j][0], startPos) > k) continue;
            answer = max(answer, prefix[j + 1] - prefix[i]);
        }

        return (int)answer;
    }
};
