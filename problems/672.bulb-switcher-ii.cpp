// @leetcode id=672 questionId=672 slug=bulb-switcher-ii lang=cpp site=leetcode.com title="Bulb Switcher II"
class Solution {
public:
    int flipLights(int n, int presses) {
        // Only the pattern among the first min(n,6) bulbs matters, since
        // each button's effect on bulb j depends only on j mod (1, 2, 2, or
        // 3), and only the parity of each button's press count matters.
        int m = min(n, 6);
        set<vector<bool>> patterns;

        for (int mask = 0; mask < 16; mask++) {
            bool p1 = mask & 1, p2 = mask & 2, p3 = mask & 4, p4 = mask & 8;
            int sumParities = p1 + p2 + p3 + p4;
            if (sumParities > presses) continue;
            if ((presses - sumParities) % 2 != 0) continue;

            vector<bool> state(m, true);
            for (int j = 0; j < m; j++) {
                int label = j + 1;
                bool flip = false;
                if (p1) flip = !flip;
                if (p2 && label % 2 == 0) flip = !flip;
                if (p3 && label % 2 == 1) flip = !flip;
                if (p4 && label % 3 == 1) flip = !flip;
                if (flip) state[j] = !state[j];
            }
            patterns.insert(state);
        }
        return patterns.size();
    }
};
