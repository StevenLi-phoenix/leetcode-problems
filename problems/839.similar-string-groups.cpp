// @leetcode id=839 questionId=869 slug=similar-string-groups lang=cpp site=leetcode.com title="Similar String Groups"
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a != b) parent[a] = b;
        };

        auto isSimilar = [&](const string& a, const string& b) {
            int diff = 0;
            for (int i = 0; i < (int)a.size() && diff <= 2; i++)
                if (a[i] != b[i]) diff++;
            return diff <= 2;
        };

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (find(i) != find(j) && isSimilar(strs[i], strs[j])) unite(i, j);

        int groups = 0;
        for (int i = 0; i < n; i++) if (find(i) == i) groups++;
        return groups;
    }
};
