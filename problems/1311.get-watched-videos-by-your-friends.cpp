// @leetcode id=1311 questionId=1436 slug=get-watched-videos-by-your-friends lang=cpp site=leetcode.com title="Get Watched Videos by Your Friends"
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<int> dist(n, -1);
        queue<int> q;
        dist[id] = 0;
        q.push(id);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : friends[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        unordered_map<string, int> freq;
        for (int i = 0; i < n; i++) {
            if (dist[i] == level) {
                for (auto& video : watchedVideos[i]) freq[video]++;
            }
        }

        vector<pair<string, int>> items(freq.begin(), freq.end());
        sort(items.begin(), items.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });

        vector<string> result;
        for (auto& [video, cnt] : items) result.push_back(video);
        return result;
    }
};
