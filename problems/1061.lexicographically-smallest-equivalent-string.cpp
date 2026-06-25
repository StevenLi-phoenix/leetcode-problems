// @leetcode id=1061 questionId=1058 slug=lexicographically-smallest-equivalent-string lang=cpp site=leetcode.com title="Lexicographically Smallest Equivalent String"
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> parent(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = 'a' + i;
        }

        function<char(char)> find = [&](char c) -> char {
            if (parent[c - 'a'] != c) {
                parent[c - 'a'] = find(parent[c - 'a']);
            }
            return parent[c - 'a'];
        };

        auto unite = [&](char a, char b) {
            char ra = find(a);
            char rb = find(b);
            if (ra != rb) {
                char smallest = min(ra, rb);
                char largest = max(ra, rb);
                parent[largest - 'a'] = smallest;
            }
        };

        for (int i = 0; i < s1.size(); i++) {
            unite(s1[i], s2[i]);
        }

        string result = baseStr;
        for (int i = 0; i < result.size(); i++) {
            result[i] = find(result[i]);
        }

        return result;
    }
};
