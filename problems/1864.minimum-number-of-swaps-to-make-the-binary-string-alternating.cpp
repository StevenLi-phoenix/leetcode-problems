// @leetcode id=1864 questionId=1994 slug=minimum-number-of-swaps-to-make-the-binary-string-alternating lang=cpp site=leetcode.com title="Minimum Number of Swaps to Make the Binary String Alternating"
class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');
        int zeros = n - ones;
        if (abs(ones - zeros) > 1) return -1;

        if (ones == zeros) {
            return min(swapsFor(s, '0'), swapsFor(s, '1'));
        }
        return swapsFor(s, ones > zeros ? '1' : '0');
    }

private:
    int swapsFor(const string& s, char start) {
        int wrong = 0;
        char expect = start;
        for (char c : s) {
            if (c != expect) ++wrong;
            expect = (expect == '0') ? '1' : '0';
        }
        return wrong / 2;
    }
};
