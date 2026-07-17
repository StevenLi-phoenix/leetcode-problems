// @leetcode id=1960 questionId=1336 slug=maximum-product-of-the-length-of-two-palindromic-substrings lang=cpp site=leetcode.com title="Maximum Product of the Length of Two Palindromic Substrings"
class Solution {
public:
    vector<int> manacherOdd(const string& s) {
        int n = s.size();
        vector<int> radius(n, 1);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : min(radius[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            radius[i] = k;
            if (i + k - 1 > r) { l = i - k + 1; r = i + k - 1; }
        }
        return radius;
    }

    long long maxProduct(string s) {
        int n = s.size();
        vector<int> radius = manacherOdd(s);

        // f[i]: max odd palindrome length with right endpoint <= i
        vector<int> bestEndAt(n);
        deque<int> dq;
        for (int p = 0; p < n; p++) {
            dq.push_back(p);
            while (!dq.empty() && (dq.front() + radius[dq.front()] - 1) < p) dq.pop_front();
            int c = dq.front();
            bestEndAt[p] = 2 * (p - c) + 1;
        }
        vector<int> f(n);
        f[0] = bestEndAt[0];
        for (int i = 1; i < n; i++) f[i] = max(f[i - 1], bestEndAt[i]);

        // g[i]: max odd palindrome length with left endpoint >= i
        vector<int> bestStartAt(n);
        deque<int> dq2;
        for (int p = n - 1; p >= 0; p--) {
            dq2.push_back(p);
            while (!dq2.empty() && (dq2.front() - radius[dq2.front()] + 1) > p) dq2.pop_front();
            int c = dq2.front();
            bestStartAt[p] = 2 * (c - p) + 1;
        }
        vector<int> g(n);
        g[n - 1] = bestStartAt[n - 1];
        for (int i = n - 2; i >= 0; i--) g[i] = max(g[i + 1], bestStartAt[i]);

        long long answer = 0;
        for (int i = 0; i + 1 < n; i++) {
            answer = max(answer, (long long)f[i] * g[i + 1]);
        }

        return answer;
    }
};
