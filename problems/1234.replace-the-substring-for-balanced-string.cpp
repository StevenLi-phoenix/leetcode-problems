// @leetcode id=1234 questionId=1351 slug=replace-the-substring-for-balanced-string lang=cpp site=leetcode.com title="Replace the Substring for Balanced String"
class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int target = n / 4;
        unordered_map<char, int> count;
        for (char c : s) count[c]++;

        auto isBalanced = [&]() {
            for (char c : string("QWER")) {
                if (count[c] > target) return false;
            }
            return true;
        };

        if (isBalanced()) return 0;

        int left = 0, best = n;
        for (int right = 0; right < n; right++) {
            count[s[right]]--;
            while (left <= right && isBalanced()) {
                best = min(best, right - left + 1);
                count[s[left]]++;
                left++;
            }
        }
        return best;
    }
};
