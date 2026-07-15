// @leetcode id=2120 questionId=2239 slug=execution-of-all-suffix-instructions-staying-in-a-grid lang=cpp site=leetcode.com title="Execution of All Suffix Instructions Staying in a Grid"
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> answer(m, 0);
        for (int start = 0; start < m; start++) {
            int r = startPos[0], c = startPos[1];
            int count = 0;
            for (int i = start; i < m; i++) {
                int nr = r, nc = c;
                if (s[i] == 'L') nc--;
                else if (s[i] == 'R') nc++;
                else if (s[i] == 'U') nr--;
                else nr++;
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) break;
                r = nr;
                c = nc;
                count++;
            }
            answer[start] = count;
        }
        return answer;
    }
};
