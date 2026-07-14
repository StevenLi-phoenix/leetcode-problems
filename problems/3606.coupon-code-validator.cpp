// @leetcode id=3606 questionId=3934 slug=coupon-code-validator lang=cpp site=leetcode.com title="Coupon Code Validator"
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, int> order = {
            {"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}
        };

        auto isValidCode = [](const string& s) {
            if (s.empty()) return false;
            for (char c : s) {
                if (!isalnum((unsigned char)c) && c != '_') return false;
            }
            return true;
        };

        vector<pair<int, string>> valid;
        for (int i = 0; i < (int)code.size(); i++) {
            if (!isActive[i]) continue;
            if (!isValidCode(code[i])) continue;
            auto it = order.find(businessLine[i]);
            if (it == order.end()) continue;
            valid.push_back({it->second, code[i]});
        }

        sort(valid.begin(), valid.end());
        vector<string> result;
        for (auto& [ord, c] : valid) result.push_back(c);
        return result;
    }
};
