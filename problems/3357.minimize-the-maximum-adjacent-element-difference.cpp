// @leetcode id=3357 questionId=3658 slug=minimize-the-maximum-adjacent-element-difference lang=cpp site=leetcode.com title="Minimize the Maximum Adjacent Element Difference"
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pos;
        for (int x : nums) if (x != -1) pos.push_back(x);
        if (pos.empty()) return 0;
        
        // Find min and max of values ADJACENT to -1 positions
        int adjMin = INT_MAX, adjMax = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] != -1) {
                // Check if adjacent to a -1
                bool adj = false;
                if (i > 0 && nums[i-1] == -1) adj = true;
                if (i + 1 < n && nums[i+1] == -1) adj = true;
                if (adj) {
                    adjMin = min(adjMin, nums[i]);
                    adjMax = max(adjMax, nums[i]);
                }
            }
        }
        
        // If no -1s exist, adjMin/adjMax are unused
        // Max of all positive values (for binary search upper bound)
        int maxPos = *max_element(pos.begin(), pos.end());
        int minPos = *min_element(pos.begin(), pos.end());
        
        auto check = [&](long long d) -> bool {
            // Check all fixed adjacent pairs
            for (int i = 0; i + 1 < n; i++) {
                if (nums[i] != -1 && nums[i+1] != -1) {
                    if (abs(nums[i] - nums[i+1]) > d) return false;
                }
            }
            
            if (adjMin == INT_MAX) return true; // no -1s
            
            // x = adjMin + d
            long long x = (long long)adjMin + d;
            
            // ylo, yhi: valid range for y
            long long ylo = 1, yhi = 2000000000LL;
            
            auto xCovers = [&](long long v) -> bool { return abs(v - x) <= d; };
            
            // Process all -1 segments
            for (int i = 0; i < n; ) {
                if (nums[i] == -1) { i++; continue; }
                
                if (i + 1 < n && nums[i+1] == -1) {
                    int a = nums[i];
                    int j = i + 1;
                    while (j < n && nums[j] == -1) j++;
                    int runLen = j - (i + 1);
                    int endVal = (j < n) ? nums[j] : -1;
                    
                    if (endVal == -1) {
                        // Trailing -1s, only a matters
                        if (!xCovers(a)) {
                            ylo = max(ylo, (long long)a - d);
                            yhi = min(yhi, (long long)a + d);
                        }
                    } else if (runLen == 1) {
                        // Single -1: need ONE value in {x,y} to cover BOTH a and endVal
                        bool xOk = xCovers(a) && xCovers(endVal);
                        if (!xOk) {
                            // y must cover both
                            ylo = max(ylo, max((long long)a - d, (long long)endVal - d));
                            yhi = min(yhi, min((long long)a + d, (long long)endVal + d));
                        }
                    } else {
                        // runLen >= 2: each endpoint independently covered, but may need mixing
                        bool xCovA = xCovers(a);
                        bool xCovB = xCovers(endVal);
                        
                        if (xCovA && xCovB) {
                            // x covers both, no constraint on y from this run
                        } else if (!xCovA && !xCovB) {
                            // Both must be covered by y
                            ylo = max(ylo, max((long long)a - d, (long long)endVal - d));
                            yhi = min(yhi, min((long long)a + d, (long long)endVal + d));
                        } else {
                            // x covers exactly one endpoint
                            long long uncoveredVal = xCovA ? (long long)endVal : (long long)a;
                            long long coveredVal = xCovA ? (long long)a : (long long)endVal;
                            
                            // Option A: y covers uncovered + |x-y|<=d (must mix)
                            long long opA_lo = max(uncoveredVal - d, x - d);
                            long long opA_hi = min(uncoveredVal + d, x + d);
                            
                            // Option B: y covers BOTH endpoints
                            long long opB_lo = max(coveredVal - d, uncoveredVal - d);
                            long long opB_hi = min(coveredVal + d, uncoveredVal + d);
                            
                            bool opAValid = opA_lo <= opA_hi;
                            bool opBValid = opB_lo <= opB_hi;
                            
                            if (!opAValid && !opBValid) return false;
                            
                            if (opAValid && opBValid) {
                                // Union of two ranges - take the broader constraint
                                long long uLo = min(opA_lo, opB_lo);
                                long long uHi = max(opA_hi, opB_hi);
                                ylo = max(ylo, uLo);
                                yhi = min(yhi, uHi);
                            } else if (opAValid) {
                                ylo = max(ylo, opA_lo);
                                yhi = min(yhi, opA_hi);
                            } else {
                                ylo = max(ylo, opB_lo);
                                yhi = min(yhi, opB_hi);
                            }
                        }
                    }
                    
                    i = j;
                    continue;
                }
                i++;
            }
            
            // Handle leading -1s
            {
                int j = 0;
                while (j < n && nums[j] == -1) j++;
                if (j > 0 && j < n) {
                    int b = nums[j];
                    if (!xCovers(b)) {
                        ylo = max(ylo, (long long)b - d);
                        yhi = min(yhi, (long long)b + d);
                    }
                }
            }
            
            return ylo <= yhi;
        };
        
        // Upper bound: if no -1s adj, return max fixed diff
        if (adjMin == INT_MAX) {
            int ans = 0;
            for (int i = 0; i + 1 < n; i++) {
                ans = max(ans, abs(nums[i] - nums[i+1]));
            }
            return ans;
        }
        
        int lo = 0, hi = adjMax - adjMin;
        // Also need to handle the case where the spread is large
        // Upper bound: max possible answer from fixed pairs + spread
        hi = max(hi, maxPos - minPos);
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }
        
        return lo;
    }
};
