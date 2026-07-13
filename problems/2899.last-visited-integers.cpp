// @leetcode id=2899 questionId=3164 slug=last-visited-integers lang=cpp site=leetcode.com title="Last Visited Integers"
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen, ans;
        int k = 0;
        for (int v : nums) {
            if (v == -1) {
                k++;
                ans.push_back(k <= (int)seen.size() ? seen[k - 1] : -1);
            } else {
                seen.insert(seen.begin(), v);
                k = 0;
            }
        }
        return ans;
    }
};
