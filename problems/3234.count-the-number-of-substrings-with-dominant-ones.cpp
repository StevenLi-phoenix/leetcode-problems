// @leetcode id=3234 questionId=3479 slug=count-the-number-of-substrings-with-dominant-ones lang=cpp site=leetcode.com title="Count the Number of Substrings With Dominant Ones"
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> zeroIdx;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zeroIdx.push_back(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(zeroIdx.begin(), zeroIdx.end(), i) - zeroIdx.begin();

            long long lowJ = i;
            long long highJ = (idx < (int)zeroIdx.size()) ? zeroIdx[idx] - 1 : n - 1;
            if (highJ >= lowJ) total += highJ - lowJ + 1;

            for (long long z = 1; z * z <= n; z++) {
                int pos = idx + (int)z - 1;
                if (pos >= (int)zeroIdx.size()) break;
                long long zeroPosZ = zeroIdx[pos];
                long long lo = zeroPosZ;
                long long hi = (pos + 1 < (int)zeroIdx.size()) ? zeroIdx[pos + 1] - 1 : n - 1;
                long long minJRequired = i - 1 + z + z * z;
                long long actualLow = max(lo, minJRequired);
                if (actualLow <= hi) total += hi - actualLow + 1;
            }
        }
        return (int)total;
    }
};
