// @leetcode id=2949 questionId=3208 slug=count-beautiful-substrings-ii lang=cpp site=leetcode.com title="Count Beautiful Substrings II"
class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        int n = s.size();

        // compute v0 = minimal v such that v*v % k == 0
        int kk = k;
        long long v0 = 1;
        for (long long p = 2; p * p <= kk; p++) {
            if (kk % p == 0) {
                int e = 0;
                while (kk % p == 0) { kk /= p; e++; }
                long long need = (e + 1) / 2;
                for (int i = 0; i < need; i++) v0 *= p;
            }
        }
        if (kk > 1) v0 *= kk; // remaining prime factor, exponent1 -> need1

        auto isVowel = [](char c) {
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };

        unordered_map<long long,int> count;
        long long diff = 0;
        long long vowelCount = 0;
        long long answer = 0;

        auto makeKey = [&](long long d, long long vm) {
            return (d + n + 1) * (v0 + 1) + vm;
        };

        count[makeKey(0, 0)] = 1;

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) { diff++; vowelCount++; }
            else diff--;

            long long vm = vowelCount % v0;
            long long key = makeKey(diff, vm);
            auto it = count.find(key);
            if (it != count.end()) {
                answer += it->second;
                it->second++;
            } else {
                count[key] = 1;
            }
        }

        return answer;
    }
};
