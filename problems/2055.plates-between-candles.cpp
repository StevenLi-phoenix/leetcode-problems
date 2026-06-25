// @leetcode id=2055 questionId=2165 slug=plates-between-candles lang=cpp site=leetcode.com title="Plates Between Candles"
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> plateCount(n + 1, 0);
        for (int i = 0; i < n; i++) {
            plateCount[i + 1] = plateCount[i] + (s[i] == '*' ? 1 : 0);
        }

        vector<int> nextCandle(n, -1);
        int lastCandle = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|') {
                lastCandle = i;
            }
            nextCandle[i] = lastCandle;
        }

        vector<int> prevCandle(n, -1);
        lastCandle = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') {
                lastCandle = i;
            }
            prevCandle[i] = lastCandle;
        }

        vector<int> result;
        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];

            int leftCandle = nextCandle[left] == -1 ? -1 : nextCandle[left];
            int rightCandle = prevCandle[right] == -1 ? -1 : prevCandle[right];

            if (leftCandle == -1 || rightCandle == -1 || leftCandle >= rightCandle) {
                result.push_back(0);
            } else {
                result.push_back(plateCount[rightCandle] - plateCount[leftCandle + 1]);
            }
        }

        return result;
    }
};
