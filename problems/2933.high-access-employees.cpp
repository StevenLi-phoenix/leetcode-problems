// @leetcode id=2933 questionId=3202 slug=high-access-employees lang=cpp site=leetcode.com title="High-Access Employees"
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> times;
        for (auto& e : access_times) {
            string name = e[0];
            int hh = stoi(e[1].substr(0, 2));
            int mm = stoi(e[1].substr(2, 2));
            times[name].push_back(hh * 60 + mm);
        }

        vector<string> result;
        for (auto& [name, mins] : times) {
            sort(mins.begin(), mins.end());
            int n = mins.size();
            for (int i = 0; i + 2 < n; i++) {
                if (mins[i + 2] - mins[i] < 60) {
                    result.push_back(name);
                    break;
                }
            }
        }
        return result;
    }
};
