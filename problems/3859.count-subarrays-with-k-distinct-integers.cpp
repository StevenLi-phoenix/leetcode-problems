// @leetcode id=3859 questionId=4002 slug=count-subarrays-with-k-distinct-integers lang=cpp site=leetcode.com title="Count Subarrays With K Distinct Integers"
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> totalCnt(maxVal + 1, 0);
        vector<vector<int>> occList(maxVal + 1);
        vector<int> oldThreshold(maxVal + 1, -1);

        vector<int> freqK(maxVal + 1, 0); // window [Lsmall, right], at most k distinct
        int distinctK = 0, Lsmall = 0;

        vector<int> freqKm1(maxVal + 1, 0); // window [Lbound, right], at most k-1 distinct
        int distinctKm1 = 0, Lbound = 0;

        multiset<int> thresholds;
        int numInvalid = 0;

        long long ans = 0;

        for (int right = 0; right < n; ++right) {
            int v = nums[right];
            bool wasPresent = freqK[v] > 0;

            if (wasPresent) {
                if (totalCnt[v] >= m) thresholds.erase(thresholds.find(oldThreshold[v]));
                else --numInvalid;
            }

            ++totalCnt[v];
            occList[v].push_back(right);

            if (totalCnt[v] >= m) {
                int nt = occList[v][totalCnt[v] - m];
                thresholds.insert(nt);
                oldThreshold[v] = nt;
            } else {
                ++numInvalid;
            }

            if (!wasPresent) ++distinctK;
            ++freqK[v];

            while (distinctK > k) {
                int u = nums[Lsmall];
                --freqK[u];
                if (freqK[u] == 0) {
                    --distinctK;
                    if (totalCnt[u] >= m) thresholds.erase(thresholds.find(oldThreshold[u]));
                    else --numInvalid;
                }
                ++Lsmall;
            }

            if (k >= 2) {
                if (freqKm1[v] == 0) ++distinctKm1;
                ++freqKm1[v];
                while (distinctKm1 > k - 1) {
                    int u = nums[Lbound];
                    --freqKm1[u];
                    if (freqKm1[u] == 0) --distinctKm1;
                    ++Lbound;
                }
            } else {
                // k == 1: "at most 0 distinct" means Lbound must equal right+1 (empty window)
                Lbound = right + 1;
            }

            if (distinctK == k && Lbound > Lsmall && numInvalid == 0) {
                int Lfreq = *thresholds.begin();
                int rangeHigh = min(Lbound - 1, Lfreq);
                if (rangeHigh >= Lsmall) ans += (rangeHigh - Lsmall + 1);
            }
        }

        return ans;
    }
};
