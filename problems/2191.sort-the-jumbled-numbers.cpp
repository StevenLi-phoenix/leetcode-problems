// @leetcode id=2191 questionId=1333 slug=sort-the-jumbled-numbers lang=cpp site=leetcode.com title="Sort the Jumbled Numbers"
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto mapValue = [&](int num) -> int {
            if (num == 0) return mapping[0];
            string s = to_string(num);
            for (char& c : s) c = '0' + mapping[c - '0'];
            return stoi(s);
        };

        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        vector<int> mapped(n);
        for (int i = 0; i < n; ++i) mapped[i] = mapValue(nums[i]);

        stable_sort(idx.begin(), idx.end(), [&](int a, int b) {
            return mapped[a] < mapped[b];
        });

        vector<int> result(n);
        for (int i = 0; i < n; ++i) result[i] = nums[idx[i]];
        return result;
    }
};
