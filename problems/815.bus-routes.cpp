// @leetcode id=815 questionId=833 slug=bus-routes lang=cpp site=leetcode.com title="Bus Routes"
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        // Map each stop to which routes pass through it
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < (int)routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }
        
        // BFS on routes
        unordered_set<int> visitedRoutes;
        unordered_set<int> visitedStops;
        queue<int> q; // stops to process
        
        visitedStops.insert(source);
        q.push(source);
        int buses = 0;
        
        while (!q.empty()) {
            buses++;
            int sz = q.size();
            // Process all stops in current level
            // But we need to expand all routes from these stops
            // Let's restructure: BFS level = number of buses taken
            
            // Collect all routes accessible from current stops
            vector<int> nextStops;
            while (sz--) {
                int stop = q.front();
                q.pop();
                for (int route : stopToRoutes[stop]) {
                    if (visitedRoutes.count(route)) continue;
                    visitedRoutes.insert(route);
                    for (int s : routes[route]) {
                        if (s == target) return buses;
                        if (!visitedStops.count(s)) {
                            visitedStops.insert(s);
                            q.push(s);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
