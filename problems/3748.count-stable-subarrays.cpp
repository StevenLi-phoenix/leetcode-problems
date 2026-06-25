// @leetcode id=3748 questionId=4110 slug=count-stable-subarrays lang=cpp site=leetcode.com title="Count Stable Subarrays"
class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // streak[i] = length of non-decreasing run ending at i
        vector<long long> streak(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i-1]) {
                streak[i] = streak[i-1] + 1;
            }
        }
        // prefix[i] = total count of stable subarrays ending at index <= i
        // For each position i, it adds streak[i] stable subarrays (lengths 1, 2, ..., streak[i])
        vector<long long> prefix(n, 0);
        prefix[0] = 1;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + streak[i];
        }
        // next[i] = first index j > i where streak[j] == 1 (i.e., next break)
        // Actually: next[i] = i + streak[i], i.e., the start of the next segment after i's segment
        // Wait: streak[i] = length ending at i
        // The segment containing i starts at i - streak[i] + 1
        // The segment containing i ends at some index end_i where streak[end_i] is maximum
        // next[i] = start of next segment after i's segment
        // We need next_seg_start[i] = first index j > i such that nums[j] < nums[j-1]
        // Or more precisely: the first index in the NEXT non-decreasing segment starting after i's segment
        
        // segEnd[i] = end of the non-decreasing segment that i belongs to
        // We compute for each i: the index where the current segment ends
        // Then next_seg_start = segEnd[i] + 1
        
        // Compute segEnd: from right
        vector<int> segStart(n);
        segStart[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i-1]) {
                segStart[i] = segStart[i-1];
            } else {
                segStart[i] = i;
            }
        }
        
        int q = queries.size();
        vector<long long> ans(q);
        
        for (int qi = 0; qi < q; qi++) {
            int l = queries[qi][0], r = queries[qi][1];
            
            // The segment containing l starts at segStart[l]
            // Find where this segment ends (last index with same segStart)
            // Actually we need: first index >= l that starts a NEW segment
            // = first index j > l such that segStart[j] > segStart[l]
            // Since segStart is non-decreasing and changes exactly at segment breaks,
            // the next segment after l's segment starts at the first j where segStart[j] != segStart[l]
            // segStart[j] = j when nums[j] < nums[j-1], so the segment end = j where segStart[j] first changes
            // The segment end for l = first index j > segStart[l] where segStart[j] == j
            // Since streak[j] = 1 exactly when segStart[j] == j (a break happened)
            // We just need: nxt = the next index j > segStart[l] + something where streak[j] == 1
            // Or: nxt = segStart[l] + (length of l's segment)
            // The segment starting at segStart[l] continues until streak stops incrementing
            // streak[l] = l - segStart[l] + 1
            // So the full segment has some end: the end is when we find j where segStart[j] != segStart[l]
            // Length from l to end of segment = streak at segment end - streak[l] + 1 = ...
            // Simpler: the end of l's segment can be found using streak:
            // from i, the segment end e satisfies streak[e] = e - segStart[l] + 1
            // and streak[e+1] = 1 (or e = n-1)
            
            // Let's precompute segEnd[i] = end of the segment that i belongs to
            // We can do this in a forward pass
            // Actually the simplest is: 
            // The number of elements in l's segment from l to r is:
            //   min(r, end_of_l_segment) - l + 1
            // Where end_of_l_segment = first index j >= segStart[l] where next element breaks
            // = segStart[l+1] ... no
            
            // Let me use a simpler method:
            // next_break[i] = smallest j > i such that nums[j] < nums[j-1], or n if none
            // Then the segment containing l ends at next_break[l] - 1
            // And the elements from l to min(r, next_break[l]-1) form an arithmetic sequence contribution
            
            long long result = 0;
            // For the first part: positions l to end of l's segment (capped at r)
            // streak at position l is l - segStart[l] + 1
            // The segment end from l: we go forward while in same segment
            // next_break for l's segment = next i where segStart[i] != segStart[l]
            // We can binary search or precompute
            
            // For now: end of l's segment
            // streak[l] = number of consecutive non-decreasing elements ending at l
            // The segment end can be found by the first j > l where streak[j] == 1 (if j <= r)
            // But this isn't trivially precomputed... let me just precompute segEnd
            
            // Actually streak[i] tells us the segment: segStart[i] = i - streak[i] + 1
            // The segment containing l ends at some e where streak[e] = e - segStart[l] + 1
            // and either e == n-1 or streak[e+1] == 1
            // We can precompute this
            
            // For now let's do it inline with binary search on streak
            // end of segment of l = largest e such that segStart[e] == segStart[l]
            // segStart[l] = l - streak[l] + 1
            // We binary search for largest e in [l, n-1] where segStart[e] == segStart[l]
            
            int ss = segStart[l];
            int lo = l, hi = n - 1, segEnd_l = l;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (segStart[mid] == ss) {
                    segEnd_l = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            
            int end1 = min(r, segEnd_l);
            long long len = end1 - l + 1;
            result += len * (len + 1) / 2;
            
            // Second part: from segEnd_l + 1 to r (if any)
            if (segEnd_l < r) {
                int start2 = segEnd_l + 1;
                result += prefix[r] - prefix[start2 - 1];
            }
            
            ans[qi] = result;
        }
        
        return ans;
    }
};
