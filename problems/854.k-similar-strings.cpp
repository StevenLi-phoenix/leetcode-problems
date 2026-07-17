// @leetcode id=854 questionId=884 slug=k-similar-strings lang=cpp site=leetcode.com title="K-Similar Strings"
class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        int n = s1.size();

        unordered_set<string> visited;
        queue<string> q;
        q.push(s1);
        visited.insert(s1);
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            steps++;
            for (int iter = 0; iter < sz; iter++) {
                string cur = q.front();
                q.pop();

                int i = 0;
                while (cur[i] == s2[i]) i++;

                for (int j = i + 1; j < n; j++) {
                    if (cur[j] == s2[i] && cur[j] != s2[j]) {
                        string next = cur;
                        swap(next[i], next[j]);
                        if (next == s2) return steps;
                        if (!visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
