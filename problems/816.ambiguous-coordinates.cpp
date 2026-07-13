// @leetcode id=816 questionId=834 slug=ambiguous-coordinates lang=cpp site=leetcode.com title="Ambiguous Coordinates"
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        string digits = s.substr(1, s.size() - 2);

        auto genNumbers = [](const string& d) {
            vector<string> res;
            int n = d.size();
            // no decimal point: whole string as integer, no leading zeros
            // unless it's exactly "0"
            if (n == 1 || d[0] != '0') res.push_back(d);

            for (int i = 1; i < n; i++) {
                string intPart = d.substr(0, i);
                string fracPart = d.substr(i);
                // integer part can't have leading zero unless it's "0"
                if (intPart.size() > 1 && intPart[0] == '0') continue;
                // fractional part can't have trailing zero
                if (fracPart.back() == '0') continue;
                res.push_back(intPart + "." + fracPart);
            }
            return res;
        };

        vector<string> result;
        int n = digits.size();
        for (int i = 1; i < n; i++) {
            vector<string> left = genNumbers(digits.substr(0, i));
            vector<string> right = genNumbers(digits.substr(i));
            for (auto& l : left) {
                for (auto& r : right) {
                    result.push_back("(" + l + ", " + r + ")");
                }
            }
        }
        return result;
    }
};
