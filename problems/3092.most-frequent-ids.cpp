// @leetcode id=3092 questionId=3363 slug=most-frequent-ids lang=cpp site=leetcode.com title="Most Frequent IDs"
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        unordered_map<int, long long> cnt;
        map<long long, int> freqCount; // frequency -> count of IDs with that frequency
        vector<long long> ans(n);
        
        for (int i = 0; i < n; i++) {
            int id = nums[i];
            long long delta = freq[i];
            
            if (cnt[id] > 0) {
                freqCount[cnt[id]]--;
                if (freqCount[cnt[id]] == 0) freqCount.erase(cnt[id]);
            }
            cnt[id] += delta;
            if (cnt[id] > 0) {
                freqCount[cnt[id]]++;
            }
            
            if (freqCount.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = freqCount.rbegin()->first;
            }
        }
        return ans;
    }
};
