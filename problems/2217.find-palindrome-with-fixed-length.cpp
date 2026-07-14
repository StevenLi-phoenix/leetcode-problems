// @leetcode id=2217 questionId=1375 slug=find-palindrome-with-fixed-length lang=cpp site=leetcode.com title="Find Palindrome With Fixed Length"
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int halfLen = (intLength + 1) / 2;
        long long start = 1;
        for (int i = 1; i < halfLen; i++) start *= 10;
        long long maxHalf = start * 10 - 1;

        vector<long long> ans;
        for (int q : queries) {
            long long half = start + q - 1;
            if (half > maxHalf) {
                ans.push_back(-1);
                continue;
            }
            string h = to_string(half);
            string rev = h;
            if (intLength % 2 == 1) rev.pop_back();
            reverse(rev.begin(), rev.end());
            ans.push_back(stoll(h + rev));
        }
        return ans;
    }
};
