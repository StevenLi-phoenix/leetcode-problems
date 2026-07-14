// @leetcode id=1090 questionId=1169 slug=largest-values-from-labels lang=cpp site=leetcode.com title="Largest Values From Labels"
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) { return values[a] > values[b]; });

        unordered_map<int, int> used;
        int total = 0, count = 0;
        for (int i : idx) {
            if (count >= numWanted) break;
            if (used[labels[i]] >= useLimit) continue;
            total += values[i];
            used[labels[i]]++;
            count++;
        }
        return total;
    }
};
