// @leetcode id=2305 questionId=1418 slug=fair-distribution-of-cookies lang=cpp site=leetcode.com title="Fair Distribution of Cookies"
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> childTotal(k, 0);
        best = INT_MAX;
        dfs(cookies, 0, childTotal);
        return best;
    }

private:
    int best;

    void dfs(vector<int>& cookies, int idx, vector<int>& childTotal) {
        if (idx == (int)cookies.size()) {
            int maxTotal = *max_element(childTotal.begin(), childTotal.end());
            best = min(best, maxTotal);
            return;
        }
        for (size_t c = 0; c < childTotal.size(); c++) {
            childTotal[c] += cookies[idx];
            if (childTotal[c] < best) {
                dfs(cookies, idx + 1, childTotal);
            }
            childTotal[c] -= cookies[idx];
        }
    }
};
