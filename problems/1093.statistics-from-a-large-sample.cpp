// @leetcode id=1093 questionId=1183 slug=statistics-from-a-large-sample lang=cpp site=leetcode.com title="Statistics from a Large Sample"
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int minVal = -1, maxVal = -1, mode = 0;
        long long totalCount = 0, totalSum = 0;
        long long maxFreq = 0;

        for (int v = 0; v < 256; ++v) {
            if (count[v] == 0) continue;
            if (minVal == -1) minVal = v;
            maxVal = v;
            totalCount += count[v];
            totalSum += (long long)v * count[v];
            if (count[v] > maxFreq) {
                maxFreq = count[v];
                mode = v;
            }
        }

        double mean = (double)totalSum / totalCount;

        long long mid1 = (totalCount + 1) / 2;
        long long mid2 = (totalCount + 2) / 2;
        long long cum = 0;
        int v1 = -1, v2 = -1;
        for (int v = 0; v < 256; ++v) {
            if (count[v] == 0) continue;
            cum += count[v];
            if (v1 == -1 && cum >= mid1) v1 = v;
            if (v2 == -1 && cum >= mid2) v2 = v;
            if (v1 != -1 && v2 != -1) break;
        }
        double median = (v1 + v2) / 2.0;

        return {(double)minVal, (double)maxVal, mean, median, (double)mode};
    }
};
