// @leetcode id=1600 questionId=1722 slug=throne-inheritance lang=cpp site=leetcode.com title="Throne Inheritance"
class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }

    void birth(string parentName, string childName) {
        children[parentName].push_back(childName);
    }

    void death(string name) {
        dead.insert(name);
    }

    vector<string> getInheritanceOrder() {
        vector<string> result;
        vector<pair<string, int>> stack = {{king, 0}};
        while (!stack.empty()) {
            string name = stack.back().first;
            int idx = stack.back().second;
            if (idx == 0 && !dead.count(name)) {
                result.push_back(name);
            }
            auto it = children.find(name);
            if (it != children.end() && idx < (int)it->second.size()) {
                string next = it->second[idx];
                stack.back().second++;
                stack.push_back({next, 0});
            } else {
                stack.pop_back();
            }
        }
        return result;
    }

private:
    string king;
    unordered_map<string, vector<string>> children;
    unordered_set<string> dead;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
