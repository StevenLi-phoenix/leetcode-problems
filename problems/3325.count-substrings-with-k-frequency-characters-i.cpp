// @leetcode id=3325 questionId=3502 slug=count-substrings-with-k-frequency-characters-i lang=cpp site=leetcode.com title="Count Substrings With K-Frequency Characters I"
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        vector<int> count(26, 0);
        int left = 0;
        long long result = 0;

        for (int right = 0; right < n; right++) {
            count[s[right] - 'a']++;
            while (count[s[right] - 'a'] >= k) {
                count[s[left] - 'a']--;
                left++;
            }
            result += left;
        }
        return (int)result;
    }
};
