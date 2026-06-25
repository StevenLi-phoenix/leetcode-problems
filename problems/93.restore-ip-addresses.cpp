// @leetcode id=93 questionId=93 slug=restore-ip-addresses lang=cpp site=leetcode.com title="Restore IP Addresses"
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> parts;
        
        function<void(int)> backtrack = [&](int start) {
            if (parts.size() == 4 && start == s.size()) {
                result.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
                return;
            }
            if (parts.size() == 4 || start == s.size()) return;
            
            for (int len = 1; len <= 3; len++) {
                if (start + len > s.size()) break;
                string part = s.substr(start, len);
                // No leading zeros (except "0" itself)
                if (part.size() > 1 && part[0] == '0') break;
                // Must be <= 255
                if (stoi(part) > 255) break;
                parts.push_back(part);
                backtrack(start + len);
                parts.pop_back();
            }
        };
        
        backtrack(0);
        return result;
    }
};
