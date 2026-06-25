// @leetcode id=3800 questionId=4156 slug=minimum-cost-to-make-two-binary-strings-equal lang=cpp site=leetcode.com title="Minimum Cost to Make Two Binary Strings Equal"
class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n = s.size();
        long long a = 0, b = 0; // a: s[i]='0',t[i]='1'; b: s[i]='1',t[i]='0'
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                if (s[i] == '0') a++;
                else b++;
            }
        }
        long long ans = 0;
        // Pair opposite mismatches
        long long p = min(a, b);
        ans += p * min((long long)swapCost, 2LL * flipCost);
        a -= p; b -= p;
        // Remaining same-type mismatches (a or b, but not both)
        long long r = a + b; // one of them is 0
        ans += (r / 2) * min((long long)crossCost + swapCost, 2LL * flipCost);
        if (r % 2 == 1) ans += flipCost;
        return ans;
    }
};
