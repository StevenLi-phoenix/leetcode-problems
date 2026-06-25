// @leetcode id=2092 questionId=2213 slug=find-all-people-with-secret lang=cpp site=leetcode.com title="Find All People With Secret"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });

        vector<char> know(n, false);
        know[0] = true;
        know[firstPerson] = true;

        vector<vector<int>> g(n);      // temporary graph for one time block
        vector<char> vis(n, false);    // temporary visited for one time block

        int m = (int)meetings.size();
        int i = 0;

        while (i < m) {
            int t = meetings[i][2];
            int j = i;

            vector<int> people;
            // Build graph for all meetings at time t
            while (j < m && meetings[j][2] == t) {
                int x = meetings[j][0], y = meetings[j][1];
                g[x].push_back(y);
                g[y].push_back(x);
                people.push_back(x);
                people.push_back(y);
                ++j;
            }

            sort(people.begin(), people.end());
            people.erase(unique(people.begin(), people.end()), people.end());

            queue<int> q;
            // Start BFS from everyone in this time block who already knows the secret
            for (int p : people) {
                if (know[p] && !vis[p]) {
                    vis[p] = true;
                    q.push(p);
                }
            }

            // Spread within the same time block (instantaneous sharing)
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : g[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

            // Everyone reached in this time block learns the secret
            for (int p : people) {
                if (vis[p]) know[p] = true;
            }

            // Cleanup only touched nodes (important for performance)
            for (int p : people) {
                g[p].clear();
                vis[p] = false;
            }

            i = j;
        }

        vector<int> ans;
        for (int p = 0; p < n; ++p) {
            if (know[p]) ans.push_back(p);
        }
        return ans;
    }
};
