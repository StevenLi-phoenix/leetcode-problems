// @leetcode id=1604 questionId=1709 slug=alert-using-same-key-card-three-or-more-times-in-a-one-hour-period lang=cpp site=leetcode.com title="Alert Using Same Key-Card Three or More Times in a One Hour Period"
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < (int)keyName.size(); i++) {
            string t = keyTime[i];
            int minutes = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
            mp[keyName[i]].push_back(minutes);
        }
        vector<string> result;
        for (auto& [name, times] : mp) {
            sort(times.begin(), times.end());
            for (int i = 2; i < (int)times.size(); i++) {
                if (times[i] - times[i-2] <= 60) {
                    result.push_back(name);
                    break;
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
