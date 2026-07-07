// @leetcode id=3260 questionId=3552 slug=find-the-largest-palindrome-divisible-by-k lang=cpp site=leetcode.com title="Find the Largest Palindrome Divisible by K"
class Solution {
public:
    string largestPalindrome(int n, int k) {
        vector<int> pow10mod(n);
        pow10mod[0] = 1 % k;
        for (int p = 1; p < n; ++p) pow10mod[p] = pow10mod[p - 1] * 10 % k;

        int half = (n + 1) / 2;
        vector<int> coef(half);
        for (int i = 0; i < half; ++i) {
            int mirror = n - 1 - i;
            if (mirror == i) {
                coef[i] = pow10mod[i] % k;
            } else {
                coef[i] = (pow10mod[i] + pow10mod[mirror]) % k;
            }
        }

        // canAchieve[i][r]: using positions i..half-1, can reach partial sum ≡ r (mod k)
        vector<vector<bool>> canAchieve(half + 1, vector<bool>(k, false));
        canAchieve[half][0] = true;

        for (int i = half - 1; i >= 0; --i) {
            int lo = (i == 0) ? 1 : 0;
            for (int d = lo; d <= 9; ++d) {
                for (int s = 0; s < k; ++s) {
                    if (!canAchieve[i + 1][s]) continue;
                    int r = (d * coef[i] + s) % k;
                    canAchieve[i][r] = true;
                }
            }
        }

        string half_digits(half, '0');
        int req = 0; // target: sum of remaining positions' contribution ≡ req (mod k)

        for (int i = 0; i < half; ++i) {
            int lo = (i == 0) ? 1 : 0;
            for (int d = 9; d >= lo; --d) {
                int candidateReq = ((req - d * coef[i]) % k + k) % k;
                if (canAchieve[i + 1][candidateReq]) {
                    half_digits[i] = '0' + d;
                    req = candidateReq;
                    break;
                }
            }
        }

        string result(n, '0');
        for (int i = 0; i < half; ++i) {
            result[i] = half_digits[i];
            result[n - 1 - i] = half_digits[i];
        }
        return result;
    }
};
