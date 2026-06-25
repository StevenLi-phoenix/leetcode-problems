// @leetcode id=1405 questionId=1304 slug=longest-happy-string lang=cpp site=leetcode.com title="Longest Happy String"
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Use a max heap to always pick the character with the most remaining count
        priority_queue<pair<int, char>> pq;
        
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result = "";
        
        while (!pq.empty()) {
            // Get the character with the most remaining count
            auto [count1, char1] = pq.top();
            pq.pop();
            
            // Check if we can add char1 (last char is different or result is empty)
            if (result.empty() || result.back() != char1) {
                // Add char1
                result += char1;
                count1--;
                
                // Try to add another char1 if possible and beneficial
                if (count1 > 0 && (pq.empty() || count1 > pq.top().first)) {
                    result += char1;
                    count1--;
                }
                
                if (count1 > 0) pq.push({count1, char1});
            } else {
                // Last char is same as char1, we need a different character
                if (pq.empty()) break;
                
                auto [count2, char2] = pq.top();
                pq.pop();
                
                result += char2;
                count2--;
                
                // Push back both if they have remaining counts
                if (count2 > 0) pq.push({count2, char2});
                pq.push({count1, char1});
            }
        }
        
        return result;
    }
};
