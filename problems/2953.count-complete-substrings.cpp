// @leetcode id=2953 questionId=3223 slug=count-complete-substrings lang=cpp site=leetcode.com title="Count Complete Substrings"
class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;
        
        // For each number of distinct characters t (1..26)
        for (int t = 1; t <= 26; t++) {
            int windowSize = t * k;
            if (windowSize > n) break;
            
            // Sliding window of size windowSize
            // We need to ensure adjacent chars differ by at most 2
            // Split word into segments where adjacent chars differ by at most 2
            // Then apply sliding window within each segment
            
            // Collect valid start positions for this t
            // Actually, we just slide a window and check two conditions:
            // 1. Each char in window appears exactly k times
            // 2. Adjacent chars in window differ by at most 2
            
            // Better: split word into maximal segments where adjacent chars differ by at most 2
            // Then within each segment, use sliding window of size t*k
            
            vector<int> splits = {0};
            for (int i = 1; i < n; i++) {
                if (abs(word[i] - word[i-1]) > 2) {
                    splits.push_back(i);
                }
            }
            splits.push_back(n);
            
            // Process each segment
            for (int s = 0; s + 1 < (int)splits.size(); s++) {
                int lo = splits[s], hi = splits[s+1];
                int segLen = hi - lo;
                if (segLen < windowSize) continue;
                
                // Sliding window of size windowSize within [lo, hi)
                unordered_map<char, int> freq;
                for (int i = lo; i < lo + windowSize; i++) {
                    freq[word[i]]++;
                }
                
                auto check = [&]() {
                    if ((int)freq.size() != t) return false;
                    for (auto& [c, cnt] : freq) {
                        if (cnt != k) return false;
                    }
                    return true;
                };
                
                if (check()) ans++;
                
                for (int i = lo + windowSize; i < hi; i++) {
                    // Add word[i], remove word[i - windowSize]
                    char add = word[i];
                    char rem = word[i - windowSize];
                    freq[add]++;
                    freq[rem]--;
                    if (freq[rem] == 0) freq.erase(rem);
                    if (check()) ans++;
                }
            }
        }
        
        return ans;
    }
};
