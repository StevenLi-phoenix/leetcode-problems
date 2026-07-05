// @leetcode id=636 questionId=636 slug=exclusive-time-of-functions lang=cpp site=leetcode.com title="Exclusive Time of Functions"
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        vector<int> stack;
        int prevTime = 0;

        for (auto& log : logs) {
            int p1 = log.find(':');
            int p2 = log.find(':', p1 + 1);
            int id = stoi(log.substr(0, p1));
            string type = log.substr(p1 + 1, p2 - p1 - 1);
            int time = stoi(log.substr(p2 + 1));

            if (type == "start") {
                if (!stack.empty()) result[stack.back()] += time - prevTime;
                stack.push_back(id);
                prevTime = time;
            } else {
                result[stack.back()] += time - prevTime + 1;
                stack.pop_back();
                prevTime = time + 1;
            }
        }
        return result;
    }
};
