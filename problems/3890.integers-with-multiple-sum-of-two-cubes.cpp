// @leetcode id=3890 questionId=4268 slug=integers-with-multiple-sum-of-two-cubes lang=cpp site=leetcode.com title="Integers With Multiple Sum of Two Cubes"
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<long long, int> count;
        for (long long a = 1; a * a * a * 2 <= n; a++) {
            for (long long b = a; ; b++) {
                long long sum = a * a * a + b * b * b;
                if (sum > n) break;
                count[sum]++;
            }
        }

        vector<int> result;
        for (auto& [val, cnt] : count) {
            if (cnt >= 2) result.push_back((int)val);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
