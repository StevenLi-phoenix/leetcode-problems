// @leetcode id=1338 questionId=1464 slug=reduce-array-size-to-the-half lang=cpp site=leetcode.com title="Reduce Array Size to The Half"
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int v : arr) count[v]++;

        vector<int> freqs;
        for (auto& [v, c] : count) freqs.push_back(c);
        sort(freqs.begin(), freqs.end(), greater<int>());

        int n = arr.size();
        int removed = 0, sets = 0;
        for (int f : freqs) {
            removed += f;
            sets++;
            if (removed * 2 >= n) break;
        }
        return sets;
    }
};
