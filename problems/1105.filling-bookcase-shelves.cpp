// @leetcode id=1105 questionId=1196 slug=filling-bookcase-shelves lang=cpp site=leetcode.com title="Filling Bookcase Shelves"
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            int width = 0, maxH = 0;
            // Try placing books[j..i-1] on the same shelf
            for (int j = i; j >= 1; j--) {
                width += books[j-1][0];
                if (width > shelfWidth) break;
                maxH = max(maxH, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + maxH);
            }
        }
        return dp[n];
    }
};
