// @leetcode id=468 questionId=468 slug=validate-ip-address lang=cpp site=leetcode.com title="Validate IP Address"
class Solution {
public:
    string validIPAddress(string queryIP) {
        auto split = [](const string& s, char delim) {
            vector<string> parts;
            string cur;
            for (char c : s) {
                if (c == delim) { parts.push_back(cur); cur.clear(); }
                else cur += c;
            }
            parts.push_back(cur);
            return parts;
        };

        auto isIPv4 = [&]() {
            vector<string> parts = split(queryIP, '.');
            if (parts.size() != 4) return false;
            for (const string& p : parts) {
                if (p.empty() || p.size() > 3) return false;
                if (p.size() > 1 && p[0] == '0') return false;
                for (char c : p) if (!isdigit(c)) return false;
                if (stoi(p) > 255) return false;
            }
            return true;
        };

        auto isIPv6 = [&]() {
            vector<string> parts = split(queryIP, ':');
            if (parts.size() != 8) return false;
            for (const string& p : parts) {
                if (p.empty() || p.size() > 4) return false;
                for (char c : p) if (!isxdigit(c)) return false;
            }
            return true;
        };

        if (isIPv4()) return "IPv4";
        if (isIPv6()) return "IPv6";
        return "Neither";
    }
};
