// @leetcode id=2100 questionId=2205 slug=find-good-days-to-rob-the-bank lang=cpp site=leetcode.com title="Find Good Days to Rob the Bank"
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> nonIncreasing(n, 0), nonDecreasing(n, 0);

        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) nonIncreasing[i] = nonIncreasing[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) nonDecreasing[i] = nonDecreasing[i + 1] + 1;
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nonIncreasing[i] >= time && nonDecreasing[i] >= time) result.push_back(i);
        }
        return result;
    }
};
