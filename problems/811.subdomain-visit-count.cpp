// @leetcode id=811 questionId=829 slug=subdomain-visit-count lang=cpp site=leetcode.com title="Subdomain Visit Count"
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count;
        for (auto& entry : cpdomains) {
            int spacePos = entry.find(' ');
            int rep = stoi(entry.substr(0, spacePos));
            string domain = entry.substr(spacePos + 1);

            for (int i = 0; i < (int)domain.size(); i++) {
                if (i == 0 || domain[i - 1] == '.') {
                    count[domain.substr(i)] += rep;
                }
            }
        }

        vector<string> result;
        for (auto& [domain, cnt] : count) {
            result.push_back(to_string(cnt) + " " + domain);
        }
        return result;
    }
};
