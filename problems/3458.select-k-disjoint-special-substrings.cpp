// @leetcode id=3458 questionId=3771 slug=select-k-disjoint-special-substrings lang=cpp site=leetcode.com title="Select K Disjoint Special Substrings"
class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        if (k == 0) return true;
        int n = s.size();
        
        // For each character, record first and last occurrence
        vector<int> firstOcc(26, -1), lastOcc(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (firstOcc[c] == -1) firstOcc[c] = i;
            lastOcc[c] = i;
        }
        
        // For each starting character, build the minimal special substring interval
        vector<pair<int,int>> intervals;
        
        for (int c = 0; c < 26; c++) {
            if (firstOcc[c] == -1) continue;
            
            int start = firstOcc[c];
            int end = lastOcc[c];
            
            // Expand the interval: include all chars in [start, end]
            bool valid = true;
            int i = start;
            while (i <= end) {
                int cc = s[i] - 'a';
                // If firstOcc[cc] < start, this char spans outside - invalid
                if (firstOcc[cc] < start) {
                    valid = false;
                    break;
                }
                end = max(end, lastOcc[cc]);
                i++;
            }
            
            if (valid) {
                // Check it's not the entire string
                if (!(start == 0 && end == n - 1)) {
                    intervals.push_back({start, end});
                }
            }
        }
        
        // Sort by end time for greedy interval scheduling
        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });
        
        // Greedy: select as many non-overlapping intervals as possible
        int count = 0;
        int lastEnd = -1;
        for (auto& [start, end] : intervals) {
            if (start > lastEnd) {
                count++;
                lastEnd = end;
            }
        }
        
        return count >= k;
    }
};
