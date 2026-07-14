// @leetcode id=1363 questionId=1277 slug=largest-multiple-of-three lang=cpp site=leetcode.com title="Largest Multiple of Three"
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        int sum = 0;
        for (int d : digits) sum += d;
        int rem = sum % 3;

        auto removeOneWithMod = [&](int m) -> bool {
            for (int i = 0; i < (int)digits.size(); i++) {
                if (digits[i] % 3 == m) { digits.erase(digits.begin() + i); return true; }
            }
            return false;
        };

        if (rem == 1) {
            if (!removeOneWithMod(1)) {
                removeOneWithMod(2);
                removeOneWithMod(2);
            }
        } else if (rem == 2) {
            if (!removeOneWithMod(2)) {
                removeOneWithMod(1);
                removeOneWithMod(1);
            }
        }

        sort(digits.rbegin(), digits.rend());
        if (digits.empty()) return "";
        if (digits[0] == 0) return "0";

        string result;
        for (int d : digits) result += ('0' + d);
        return result;
    }
};
