// @leetcode id=2468 questionId=2563 slug=split-message-based-on-limit lang=cpp site=leetcode.com title="Split Message Based on Limit"
class Solution {
public:
    int numDigits(int x) {
        return to_string(x).size();
    }

    vector<string> splitMessage(string message, int limit) {
        int n = message.size();

        vector<long long> digitPrefix(n + 2, 0);
        for (int a = 1; a <= n + 1; a++) digitPrefix[a] = digitPrefix[a - 1] + numDigits(a);

        int bestB = -1;
        for (int b = 1; b <= n; b++) {
            int db = numDigits(b);
            if (limit <= 3 + 2 * db) continue;

            long long overhead = (long long)b * db + digitPrefix[b] + 3LL * b;
            long long capacity = (long long)b * limit - overhead;

            if (capacity >= n) { bestB = b; break; }
        }

        if (bestB == -1) return {};

        int b = bestB;
        int db = numDigits(b);
        vector<string> result;
        int pos = 0;

        for (int a = 1; a <= b; a++) {
            int suffixLen = 3 + numDigits(a) + db;
            int contentLen = min(n - pos, limit - suffixLen);
            string part = message.substr(pos, contentLen) + "<" + to_string(a) + "/" + to_string(b) + ">";
            result.push_back(part);
            pos += contentLen;
        }

        return result;
    }
};
