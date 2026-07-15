// @leetcode id=842 questionId=872 slug=split-array-into-fibonacci-sequence lang=cpp site=leetcode.com title="Split Array into Fibonacci Sequence"
class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<long long> result;
        if (backtrack(num, 0, result)) {
            return vector<int>(result.begin(), result.end());
        }
        return {};
    }

private:
    bool backtrack(const string& num, int start, vector<long long>& result) {
        if (start == (int)num.size()) {
            return result.size() >= 3;
        }
        int maxLen = (num[start] == '0') ? 1 : 10;
        for (int len = 1; len <= maxLen && start + len <= (int)num.size(); len++) {
            string piece = num.substr(start, len);
            long long val;
            try {
                val = stoll(piece);
            } catch (...) {
                break;
            }
            if (val > INT_MAX) break;

            size_t n = result.size();
            if (n >= 2 && val != result[n - 2] + result[n - 1]) continue;

            result.push_back(val);
            if (backtrack(num, start + len, result)) return true;
            result.pop_back();
        }
        return false;
    }
};
