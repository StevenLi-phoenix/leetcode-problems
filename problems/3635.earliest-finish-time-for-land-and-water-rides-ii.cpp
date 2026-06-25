// @leetcode id=3635 questionId=3967 slug=earliest-finish-time-for-land-and-water-rides-ii lang=cpp site=leetcode.com title="Earliest Finish Time for Land and Water Rides II"
class Solution {
public:
    long long solve(vector<int>& aStart, vector<int>& aDur, 
                    vector<int>& bStart, vector<int>& bDur) {
        int n = aStart.size(), m = bStart.size();
        
        // Sort A by start time
        vector<int> aIdx(n);
        iota(aIdx.begin(), aIdx.end(), 0);
        sort(aIdx.begin(), aIdx.end(), [&](int x, int y) {
            return aStart[x] < aStart[y];
        });
        
        // Sort B by start time
        vector<int> bIdx(m);
        iota(bIdx.begin(), bIdx.end(), 0);
        sort(bIdx.begin(), bIdx.end(), [&](int x, int y) {
            return bStart[x] < bStart[y];
        });
        
        // Sorted B arrays
        vector<int> bS(m), bD(m);
        for (int i = 0; i < m; i++) {
            bS[i] = bStart[bIdx[i]];
            bD[i] = bDur[bIdx[i]];
        }
        
        // prefix min duration of B (0..i)
        vector<long long> prefMinDur(m);
        prefMinDur[0] = bD[0];
        for (int i = 1; i < m; i++) prefMinDur[i] = min(prefMinDur[i-1], (long long)bD[i]);
        
        // suffix min finish time of B (i..m-1): finish = max(bS[i], t) + bD[i]
        // But this depends on when we arrive, so we precompute bS[i] + bD[i] as the earliest
        // finish if we arrive before bS[i]
        // suffix min of (bS[i] + bD[i])
        vector<long long> sufMinFinish(m);
        sufMinFinish[m-1] = (long long)bS[m-1] + bD[m-1];
        for (int i = m-2; i >= 0; i--) 
            sufMinFinish[i] = min(sufMinFinish[i+1], (long long)bS[i] + bD[i]);
        
        long long ans = LLONG_MAX;
        
        for (int i = 0; i < n; i++) {
            int ai = aIdx[i];
            long long finA = (long long)aStart[ai] + aDur[ai];
            
            // Binary search in bS for rides with bS[j] <= finA
            int lo = 0, hi = m - 1, pos = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (bS[mid] <= finA) { pos = mid; lo = mid + 1; }
                else hi = mid - 1;
            }
            
            if (pos >= 0) {
                // B ride opens before we finish A: arrive at finA, can board immediately
                // finish = finA + minDuration(0..pos)
                ans = min(ans, finA + prefMinDur[pos]);
            }
            if (pos < m - 1) {
                // B ride opens after we finish A: must wait
                // finish = bS[j] + bD[j], minimize over j > pos
                ans = min(ans, sufMinFinish[pos + 1]);
            }
        }
        
        return ans;
    }
    
    long long earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                                  vector<int>& waterStartTime, vector<int>& waterDuration) {
        long long a = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        long long b = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(a, b);
    }
};
