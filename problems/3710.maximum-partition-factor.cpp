// @leetcode id=3710 questionId=4035 slug=maximum-partition-factor lang=cpp site=leetcode.com title="Maximum Partition Factor"
class Solution {
public:
    vector<int> parent, parity;

    int find(int x, int& p) {
        if (parent[x] == x) { p = 0; return x; }
        int pp;
        int root = find(parent[x], pp);
        parity[x] ^= pp;
        parent[x] = root;
        p = parity[x];
        return root;
    }

    bool unite(int a, int b) {
        int pa, pb;
        int ra = find(a, pa), rb = find(b, pb);
        if (ra == rb) {
            return (pa ^ pb) == 1;
        }
        parent[ra] = rb;
        parity[ra] = pa ^ pb ^ 1;
        return true;
    }

    bool feasible(int n, vector<vector<long long>>& dist, long long d) {
        parent.resize(n);
        parity.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dist[i][j] < d) {
                    if (!unite(i, j)) return false;
                }
            }
        }
        return true;
    }

    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 2) return 0;

        vector<vector<long long>> dist(n, vector<long long>(n, 0));
        vector<long long> allDist;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long d = abs((long long)points[i][0] - points[j][0]) + abs((long long)points[i][1] - points[j][1]);
                dist[i][j] = dist[j][i] = d;
                allDist.push_back(d);
            }
        }

        sort(allDist.begin(), allDist.end());
        allDist.erase(unique(allDist.begin(), allDist.end()), allDist.end());
        allDist.push_back(0); // ensure 0 candidate exists

        sort(allDist.begin(), allDist.end());

        int lo = 0, hi = allDist.size() - 1;
        long long best = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (feasible(n, dist, allDist[mid])) {
                best = allDist[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return (int)best;
    }
};
