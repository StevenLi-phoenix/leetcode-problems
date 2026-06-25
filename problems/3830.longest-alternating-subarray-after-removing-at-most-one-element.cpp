// @leetcode id=3830 questionId=4198 slug=longest-alternating-subarray-after-removing-at-most-one-element lang=cpp site=leetcode.com title="Longest Alternating Subarray After Removing At Most One Element"
class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // sign(a, b): 1 if a < b, -1 if a > b, 0 if a == b
        auto sign = [](int a, int b) -> int {
            if (a < b) return 1;
            if (a > b) return -1;
            return 0;
        };
        
        // Precompute comparison array: cmp[i] = sign(nums[i], nums[i+1])
        vector<int> cmp(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cmp[i] = sign(nums[i], nums[i + 1]);
        }
        
        // An alternating subarray nums[l..r] means cmp[l], cmp[l+1], ..., cmp[r-1]
        // strictly alternate signs (no zeros, alternating +1/-1)
        
        // For the subarray to be alternating:
        // cmp[i] != 0 for all i in range
        // cmp[i] * cmp[i+1] == -1 (alternates) for consecutive pairs
        
        // With at most 1 removal from nums:
        // Removing nums[j] (l < j < r) merges cmp[j-1] and cmp[j] into sign(nums[j-1], nums[j+1])
        // The new comparison at that position is sign(nums[j-1], nums[j+1])
        
        // dp0[i] = length of longest alternating subarray ending at i, no removal
        // dp1[i] = length of longest alternating subarray ending at i, exactly 1 removal
        // (removal means one element from the subarray was removed)
        
        // For dp0:
        // dp0[0] = 1
        // dp0[i] = dp0[i-1] + 1 if cmp[i-1] != 0 and (dp0[i-1] == 1 or cmp[i-1] * cmp[i-2] == -1)
        // else dp0[i] = 1 (or 2 if cmp[i-1] != 0)
        
        // For dp1:
        // dp1[i] = max(
        //   dp0[i],  // no removal
        //   extend dp1[i-1] if possible,
        //   remove nums[i-1]: dp0[i-2] extended by 1 if compatible, or 2 if nums[i-2] != nums[i]
        // )
        
        int ans = 1;
        // dp0, dp1, and we also need to know the "effective sign" at the boundary for dp1
        // Let's track: for each position, the "last cmp" value that dp0/dp1 ends with
        
        vector<int> dp0(n, 1), dp1(n, 1);
        vector<int> lastCmp0(n, 0), lastCmp1(n, 0); // last cmp direction for dp0, dp1
        
        for (int i = 1; i < n; i++) {
            // dp0[i]
            if (i == 1) {
                if (cmp[0] != 0) {
                    dp0[i] = 2;
                    lastCmp0[i] = cmp[0];
                }
            } else {
                if (cmp[i-1] != 0 && (dp0[i-1] == 1 || cmp[i-1] * lastCmp0[i-1] == -1)) {
                    dp0[i] = dp0[i-1] + 1;
                    lastCmp0[i] = cmp[i-1];
                } else if (cmp[i-1] != 0) {
                    dp0[i] = 2;
                    lastCmp0[i] = cmp[i-1];
                }
            }
            
            // dp1[i]: try to extend dp1[i-1]
            dp1[i] = dp0[i]; // at least as good as dp0
            
            // Extend dp1[i-1] with nums[i]:
            // Need cmp[i-1] != 0 and cmp[i-1] * lastCmp1[i-1] == -1
            if (dp1[i-1] > 1 && cmp[i-1] != 0 && cmp[i-1] * lastCmp1[i-1] == -1) {
                int newLen = dp1[i-1] + 1;
                if (newLen > dp1[i]) {
                    dp1[i] = newLen;
                    lastCmp1[i] = cmp[i-1];
                }
            } else if (dp1[i-1] == 1 && cmp[i-1] != 0) {
                // dp1[i-1] is just a single element, extend to 2
                int newLen = 2;
                if (newLen > dp1[i]) {
                    dp1[i] = newLen;
                    lastCmp1[i] = cmp[i-1];
                }
            }
            
            // Remove nums[i-1]: connect i-2 with i
            if (i >= 2) {
                int newCmp = sign(nums[i-2], nums[i]);
                if (newCmp != 0) {
                    if (dp0[i-2] == 1) {
                        // Just [nums[i-2], nums[i]] = length 2
                        if (2 > dp1[i]) {
                            dp1[i] = 2;
                            lastCmp1[i] = newCmp;
                        }
                    } else {
                        // Extend dp0[i-2] by removing i-1 and appending i
                        // Check: newCmp * lastCmp0[i-2] == -1?
                        if (newCmp * lastCmp0[i-2] == -1) {
                            int newLen = dp0[i-2] + 1;
                            if (newLen > dp1[i]) {
                                dp1[i] = newLen;
                                lastCmp1[i] = newCmp;
                            }
                        } else {
                            // Can't extend, just [nums[i-2], nums[i]]
                            if (2 > dp1[i]) {
                                dp1[i] = 2;
                                lastCmp1[i] = newCmp;
                            }
                        }
                    }
                }
            }
            
            // Also consider: remove first element of a subarray (extend by 1 from nothing)
            // i.e., dp1 can be dp0[i-1]+1 if we remove nums[i] from consideration... 
            // No wait, we can't remove nums[i] since that's our ending element
            // But we CAN remove the first element: [nums[1], nums[2], ...] = dp0 of tail
            // Actually dp0 already handles subarrays not starting at 0
            
            // Also: removing an element at the start: same as dp0 (just start later)
            // This is already covered by dp0[i]
            
            ans = max(ans, max(dp0[i], dp1[i]));
        }
        
        // Special case: n=1
        ans = max(ans, 1);
        
        return ans;
    }
};
