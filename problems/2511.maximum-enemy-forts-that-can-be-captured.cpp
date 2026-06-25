// @leetcode id=2511 questionId=2602 slug=maximum-enemy-forts-that-can-be-captured lang=cpp site=leetcode.com title="Maximum Enemy Forts That Can Be Captured"
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size(), ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (forts[i] != 1) continue;
            
            // Look left
            int count = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (forts[j] == 0) count++;
                else if (forts[j] == -1) { ans = max(ans, count); break; }
                else break; // hit another 1
            }
            
            // Look right
            count = 0;
            for (int j = i + 1; j < n; j++) {
                if (forts[j] == 0) count++;
                else if (forts[j] == -1) { ans = max(ans, count); break; }
                else break; // hit another 1
            }
        }
        
        return ans;
    }
};
