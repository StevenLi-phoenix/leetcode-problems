// @leetcode id=3664 questionId=3877 slug=two-letter-card-game lang=cpp site=leetcode.com title="Two-Letter Card Game"
class Solution {
public:
    // Max pairs from cards of different types (same type can't pair)
    // Include wildcards as a specific type
    int maxPairs(vector<int> cnt, int wildcards) {
        if (wildcards > 0) cnt.push_back(wildcards);
        
        int sum = 0, maxCnt = 0;
        for (int c : cnt) { sum += c; maxCnt = max(maxCnt, c); }
        
        if (sum == 0) return 0;
        // Max pairs where no two of same type: min(sum/2, sum - maxCnt)
        return min(sum / 2, sum - maxCnt);
    }
    
    int score(vector<string>& cards, char x) {
        unordered_map<char, int> cnt1, cnt2;
        int both = 0;
        
        for (auto& card : cards) {
            if (card[0] == x && card[1] == x) both++;
            else if (card[0] == x) cnt1[card[1]]++;
            else if (card[1] == x) cnt2[card[0]]++;
        }
        
        vector<int> v1, v2;
        for (auto& [c, cnt] : cnt1) v1.push_back(cnt);
        for (auto& [c, cnt] : cnt2) v2.push_back(cnt);
        
        int ans = 0;
        for (int i = 0; i <= both; i++) {
            ans = max(ans, maxPairs(v1, i) + maxPairs(v2, both - i));
        }
        return ans;
    }
};
