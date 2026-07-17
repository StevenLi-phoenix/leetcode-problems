// @leetcode id=1298 questionId=1424 slug=maximum-candies-you-can-get-from-boxes lang=cpp site=leetcode.com title="Maximum Candies You Can Get from Boxes"
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> hasBox(n, false);
        vector<bool> opened(n, false);
        vector<int> statusMut = status;
        queue<int> q;

        for (int b : initialBoxes) {
            hasBox[b] = true;
            if (statusMut[b] == 1) q.push(b);
        }

        int total = 0;
        while (!q.empty()) {
            int b = q.front();
            q.pop();
            if (opened[b]) continue;
            opened[b] = true;
            total += candies[b];

            for (int k : keys[b]) {
                statusMut[k] = 1;
                if (hasBox[k] && !opened[k]) q.push(k);
            }
            for (int c : containedBoxes[b]) {
                hasBox[c] = true;
                if (statusMut[c] == 1 && !opened[c]) q.push(c);
            }
        }

        return total;
    }
};
