// @leetcode id=3208 questionId=3483 slug=alternating-groups-ii lang=cpp site=leetcode.com title="Alternating Groups II"
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        // Use sliding window on the circular array
        // Extend array by k-1 elements to handle wrap-around
        // Count valid groups using a sliding window of size k
        
        int count = 0;
        int len = 1; // current alternating run length ending at i
        
        // We need a window of k tiles where consecutive tiles differ
        // Check each consecutive pair in circular order
        
        // Extend the check by k-1 wrap-around elements
        for (int i = 1; i < n + k - 1; i++) {
            int cur = colors[i % n];
            int prev = colors[(i - 1) % n];
            if (cur != prev) {
                len++;
            } else {
                len = 1;
            }
            if (len >= k) {
                count++;
            }
        }
        
        return count;
    }
};
