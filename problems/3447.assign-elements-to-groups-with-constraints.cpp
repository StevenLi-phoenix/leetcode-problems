// @leetcode id=3447 questionId=3760 slug=assign-elements-to-groups-with-constraints lang=cpp site=leetcode.com title="Assign Elements to Groups with Constraints"
class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int maxGroup = 0;
        for (int g : groups) maxGroup = max(maxGroup, g);

        unordered_map<int, int> firstIndex;
        for (int j = 0; j < (int)elements.size(); j++) {
            int v = elements[j];
            if (v <= maxGroup && firstIndex.find(v) == firstIndex.end()) {
                firstIndex[v] = j;
            }
        }

        vector<int> best(maxGroup + 1, -1);
        for (auto& [v, idx] : firstIndex) {
            for (int multiple = v; multiple <= maxGroup; multiple += v) {
                if (best[multiple] == -1 || idx < best[multiple]) {
                    best[multiple] = idx;
                }
            }
        }

        vector<int> result(groups.size());
        for (size_t i = 0; i < groups.size(); i++) {
            result[i] = best[groups[i]];
        }
        return result;
    }
};
