// @leetcode id=2943 questionId=3214 slug=maximize-area-of-square-hole-in-grid lang=cpp site=leetcode.com title="Maximize Area of Square Hole in Grid"
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto bestSpan = [&](vector<int>& bars) -> int {
            if (bars.empty()) return 1; // no removable bars => only 1-unit span
            sort(bars.begin(), bars.end());
            int cur = 1, best = 1;
            for (int i = 1; i < (int)bars.size(); i++) {
                if (bars[i] == bars[i - 1] + 1) cur++;
                else cur = 1;
                best = max(best, cur);
            }
            return best + 1; // L removed bars => L+1 cells merged
        };

        int H = bestSpan(hBars);
        int V = bestSpan(vBars);
        long long side = min(H, V);
        return (int)(side * side);
    }
};
