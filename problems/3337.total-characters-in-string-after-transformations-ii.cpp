// @leetcode id=3337 questionId=3630 slug=total-characters-in-string-after-transformations-ii lang=cpp site=leetcode.com title="Total Characters in String After Transformations II"
class Solution {
public:
    static const int SZ = 26;
    const long long MOD = 1e9 + 7;

    using Mat = array<array<long long, SZ>, SZ>;

    Mat multiply(const Mat& a, const Mat& b) {
        Mat res{};
        for (int i = 0; i < SZ; i++) {
            for (int k = 0; k < SZ; k++) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < SZ; j++) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Mat matpow(Mat base, long long exp) {
        Mat result{};
        for (int i = 0; i < SZ; i++) result[i][i] = 1;
        while (exp > 0) {
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Mat M{};
        for (int i = 0; i < SZ; i++) {
            for (int step = 1; step <= nums[i]; step++) {
                int j = (i + step) % SZ;
                M[j][i] = (M[j][i] + 1) % MOD;
            }
        }

        Mat Mt = matpow(M, t);

        array<long long, SZ> cnt{};
        for (char c : s) cnt[c - 'a']++;

        long long answer = 0;
        for (int j = 0; j < SZ; j++) {
            long long total = 0;
            for (int i = 0; i < SZ; i++) {
                total = (total + Mt[j][i] * (cnt[i] % MOD)) % MOD;
            }
            answer = (answer + total) % MOD;
        }

        return (int)answer;
    }
};
