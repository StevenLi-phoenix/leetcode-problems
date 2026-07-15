// @leetcode id=3964 questionId=4330 slug=minimum-lights-to-illuminate-a-road lang=cpp site=leetcode.com title="Minimum Lights to Illuminate a Road"
class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int lo = max(0, i - lights[i]);
                int hi = min(n - 1, i + lights[i]);
                diff[lo]++;
                diff[hi + 1]--;
            }
        }

        int result = 0;
        int running = 0;
        int gapLen = 0;
        for (int i = 0; i < n; i++) {
            running += diff[i];
            if (running > 0) {
                if (gapLen > 0) {
                    result += (gapLen + 2) / 3;
                    gapLen = 0;
                }
            } else {
                gapLen++;
            }
        }
        if (gapLen > 0) result += (gapLen + 2) / 3;

        return result;
    }
};
