// @leetcode id=332 questionId=332 slug=reconstruct-itinerary lang=cpp site=leetcode.com title="Reconstruct Itinerary"
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto& t : tickets) graph[t[0]].insert(t[1]);

        vector<string> result;
        stack<string> st;
        st.push("JFK");

        while (!st.empty()) {
            string cur = st.top();
            auto it = graph.find(cur);
            if (it == graph.end() || it->second.empty()) {
                result.push_back(cur);
                st.pop();
            } else {
                string next = *it->second.begin();
                it->second.erase(it->second.begin());
                st.push(next);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
