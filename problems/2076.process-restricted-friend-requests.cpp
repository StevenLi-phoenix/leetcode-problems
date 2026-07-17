// @leetcode id=2076 questionId=2198 slug=process-restricted-friend-requests lang=cpp site=leetcode.com title="Process Restricted Friend Requests"
class Solution {
public:
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        vector<bool> result;

        for (auto& req : requests) {
            int ru = find(req[0]), rv = find(req[1]);

            if (ru == rv) {
                result.push_back(true);
                continue;
            }

            bool ok = true;
            for (auto& r : restrictions) {
                int rx = find(r[0]), ry = find(r[1]);
                if ((rx == ru && ry == rv) || (rx == rv && ry == ru)) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                parent[ru] = rv;
            }
            result.push_back(ok);
        }

        return result;
    }
};
