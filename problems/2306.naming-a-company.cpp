// @leetcode id=2306 questionId=2390 slug=naming-a-company lang=cpp site=leetcode.com title="Naming a Company"
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> groups(26);
        for (string& idea : ideas) {
            groups[idea[0] - 'a'].insert(idea.substr(1));
        }

        long long total = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                long long common = 0;
                auto& smaller = groups[i].size() < groups[j].size() ? groups[i] : groups[j];
                auto& larger = groups[i].size() < groups[j].size() ? groups[j] : groups[i];
                for (const string& s : smaller) {
                    if (larger.count(s)) common++;
                }
                long long onlyI = groups[i].size() - common;
                long long onlyJ = groups[j].size() - common;
                total += 2 * onlyI * onlyJ;
            }
        }

        return total;
    }
};
