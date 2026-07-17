// @leetcode id=3704 questionId=4049 slug=count-no-zero-pairs-that-sum-to-n lang=cpp site=leetcode.com title="Count No-Zero Pairs That Sum to N"
class Solution {
public:
    vector<int> digits;
    int len;
    map<tuple<int,int,int,int>, long long> memo;

    long long dp(int pos, int carry, int aActive, int bActive) {
        if (pos == len) {
            return carry == 0 ? 1 : 0;
        }
        auto key = make_tuple(pos, carry, aActive, bActive);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        long long total = 0;
        int aLo = aActive ? 1 : 0, aHi = aActive ? 9 : 0;
        int bLo = bActive ? 1 : 0, bHi = bActive ? 9 : 0;

        for (int da = aLo; da <= aHi; da++) {
            for (int db = bLo; db <= bHi; db++) {
                int sum = da + db + carry;
                if (sum % 10 != digits[pos]) continue;
                int newCarry = sum / 10;

                if (pos + 1 == len) {
                    total += dp(pos + 1, newCarry, 0, 0);
                } else {
                    for (int aNext = 0; aNext <= (aActive ? 1 : 0); aNext++) {
                        for (int bNext = 0; bNext <= (bActive ? 1 : 0); bNext++) {
                            total += dp(pos + 1, newCarry, aNext, bNext);
                        }
                    }
                }
            }
        }

        memo[key] = total;
        return total;
    }

    long long countNoZeroPairs(long long n) {
        string s = to_string(n);
        len = s.size();
        digits.resize(len);
        for (int i = 0; i < len; i++) digits[i] = s[len - 1 - i] - '0';

        memo.clear();
        return dp(0, 0, 1, 1);
    }
};
