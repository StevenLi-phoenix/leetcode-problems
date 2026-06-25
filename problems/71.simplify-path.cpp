// @leetcode id=71 questionId=71 slug=simplify-path lang=cpp site=leetcode.com title="Simplify Path"
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        stringstream ss(path);
        string token;
        
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!stk.empty()) stk.pop();
            } else {
                stk.push(token);
            }
        }
        
        if (stk.empty()) return "/";
        
        string result = "";
        while (!stk.empty()) {
            result = "/" + stk.top() + result;
            stk.pop();
        }
        return result;
    }
};
