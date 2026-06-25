// @leetcode id=646 questionId=646 slug=maximum-length-of-pair-chain lang=cpp site=leetcode.com title="Maximum Length of Pair Chain"
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Greedy: sort by right endpoint, pick pairs with smallest right endpoint
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int chain = 1;
        int curRight = pairs[0][1];
        
        for (int i = 1; i < (int)pairs.size(); i++) {
            if (pairs[i][0] > curRight) {
                chain++;
                curRight = pairs[i][1];
            }
        }
        
        return chain;
    }
};
