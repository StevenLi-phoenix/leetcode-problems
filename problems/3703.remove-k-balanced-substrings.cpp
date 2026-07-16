// @leetcode id=3703 questionId=4019 slug=remove-k-balanced-substrings lang=cpp site=leetcode.com title="Remove K-Balanced Substrings"
class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char, long long>> stk;

        for (char c : s) {
            if (!stk.empty() && stk.back().first == c) {
                stk.back().second++;
            } else {
                stk.push_back({c, 1});
            }

            while (true) {
                // merge adjacent same-char runs (can happen after removals)
                while (stk.size() >= 2 && stk[stk.size() - 1].first == stk[stk.size() - 2].first) {
                    stk[stk.size() - 2].second += stk[stk.size() - 1].second;
                    stk.pop_back();
                }

                if (stk.size() >= 2 &&
                    stk.back().first == ')' && stk.back().second >= k &&
                    stk[stk.size() - 2].first == '(' && stk[stk.size() - 2].second >= k) {
                    stk.back().second -= k;
                    stk[stk.size() - 2].second -= k;
                    if (stk.back().second == 0) stk.pop_back();
                    if (!stk.empty() && stk.back().first == '(' && stk.back().second == 0) {
                        stk.pop_back();
                    } else if (stk.size() >= 2 && stk[stk.size() - 2].first == '(' && stk[stk.size() - 2].second == 0) {
                        stk.erase(stk.end() - 2);
                    }
                } else {
                    break;
                }
            }
        }

        string result;
        for (auto& [c, cnt] : stk) {
            result.append(cnt, c);
        }
        return result;
    }
};
