// @leetcode id=3598 questionId=3800 slug=longest-common-prefix-between-adjacent-strings-after-removals lang=cpp site=leetcode.com title="Longest Common Prefix Between Adjacent Strings After Removals"
class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        auto lcpLen = [](const string& a, const string& b) {
            int len = min(a.size(), b.size());
            int k = 0;
            while (k < len && a[k] == b[k]) k++;
            return k;
        };

        vector<pair<int, int>> lcpList; // (value, index) for pair (i, i+1)
        for (int i = 0; i + 1 < n; i++) {
            lcpList.push_back({lcpLen(words[i], words[i + 1]), i});
        }
        sort(lcpList.begin(), lcpList.end(), greater<pair<int, int>>());

        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            unordered_set<int> excluded;
            if (i - 1 >= 0) excluded.insert(i - 1);
            if (i < n - 1) excluded.insert(i);

            int best = 0;
            for (auto& [val, idx] : lcpList) {
                if (excluded.count(idx)) continue;
                best = val;
                break;
            }

            if (i - 1 >= 0 && i + 1 < n) {
                best = max(best, lcpLen(words[i - 1], words[i + 1]));
            }

            result[i] = best;
        }
        return result;
    }
};
