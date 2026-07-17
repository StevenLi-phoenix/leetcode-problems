// @leetcode id=3267 questionId=3544 slug=count-almost-equal-pairs-ii lang=cpp site=leetcode.com title="Count Almost Equal Pairs II"
class Solution {
public:
    string pad7(int x) {
        string s = to_string(x);
        while (s.size() < 7) s = "0" + s;
        return s;
    }

    bool almostEqual(const char* a, const char* b) {
        int mismatched[7];
        int diff = 0;
        for (int i = 0; i < 7; i++) {
            if (a[i] != b[i]) {
                if (diff == 4) return false;
                mismatched[diff++] = i;
            }
        }

        if (diff == 0 || diff == 2 || diff == 3) return true;
        if (diff == 4) {
            int p0 = mismatched[0], p1 = mismatched[1], p2 = mismatched[2], p3 = mismatched[3];
            auto validPair = [&](int i, int j) {
                return a[i] == b[j] && a[j] == b[i];
            };
            if (validPair(p0, p1) && validPair(p2, p3)) return true;
            if (validPair(p0, p2) && validPair(p1, p3)) return true;
            if (validPair(p0, p3) && validPair(p1, p2)) return true;
            return false;
        }
        return false;
    }

    int countPairs(vector<int>& nums) {
        unordered_map<long long, vector<array<char,7>>> groups;
        groups.reserve(nums.size() * 2);

        for (int x : nums) {
            string padded = pad7(x);
            array<char,7> digits;
            int counts[10] = {0};
            for (int i = 0; i < 7; i++) {
                digits[i] = padded[i];
                counts[padded[i] - '0']++;
            }
            long long sig = 0;
            for (int d = 0; d < 10; d++) sig = sig * 8 + counts[d];
            groups[sig].push_back(digits);
        }

        long long answer = 0;
        for (auto& [sig, list] : groups) {
            int g = list.size();
            for (int i = 0; i < g; i++) {
                const char* ai = list[i].data();
                for (int j = i + 1; j < g; j++) {
                    if (almostEqual(ai, list[j].data())) answer++;
                }
            }
        }

        return (int)answer;
    }
};
