// @leetcode id=2060 questionId=2184 slug=check-if-an-original-string-exists-given-two-encoded-strings lang=cpp site=leetcode.com title="Check if an Original String Exists Given Two Encoded Strings"
class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        map<tuple<int,int,int>, bool> memo;
        int n1 = s1.size(), n2 = s2.size();
        
        function<bool(int, int, int)> dfs = [&](int i, int j, int diff) -> bool {
            auto key = make_tuple(i, j, diff);
            auto it = memo.find(key);
            if (it != memo.end()) return it->second;
            
            bool &res = memo[key];
            res = false;
            
            if (i == n1 && j == n2) return res = (diff == 0);
            
            if (diff == 0) {
                if (i < n1 && j < n2) {
                    bool d1 = isdigit(s1[i]), d2 = isdigit(s2[j]);
                    if (d1 && d2) {
                        int num1 = 0;
                        for (int a = i; a < min(n1, i+3) && isdigit(s1[a]); a++) {
                            num1 = num1*10 + (s1[a]-'0');
                            int num2 = 0;
                            for (int b = j; b < min(n2, j+3) && isdigit(s2[b]); b++) {
                                num2 = num2*10 + (s2[b]-'0');
                                if (dfs(a+1, b+1, num1-num2)) return res = true;
                            }
                        }
                    } else if (d1) {
                        int num1 = 0;
                        for (int a = i; a < min(n1, i+3) && isdigit(s1[a]); a++) {
                            num1 = num1*10 + (s1[a]-'0');
                            if (dfs(a+1, j, num1)) return res = true;
                        }
                    } else if (d2) {
                        int num2 = 0;
                        for (int b = j; b < min(n2, j+3) && isdigit(s2[b]); b++) {
                            num2 = num2*10 + (s2[b]-'0');
                            if (dfs(i, b+1, -num2)) return res = true;
                        }
                    } else {
                        if (s1[i] == s2[j]) res = dfs(i+1, j+1, 0);
                    }
                }
            } else if (diff > 0) {
                // s1 has consumed diff more wildcards than s2; s2 must spend diff more
                if (j < n2) {
                    if (isdigit(s2[j])) {
                        int num2 = 0;
                        for (int b = j; b < min(n2, j+3) && isdigit(s2[b]); b++) {
                            num2 = num2*10 + (s2[b]-'0');
                            if (dfs(i, b+1, diff-num2)) return res = true;
                        }
                    } else {
                        res = dfs(i, j+1, diff-1);
                    }
                }
            } else { // diff < 0
                // s2 has consumed |diff| more wildcards than s1; s1 must spend |diff| more
                if (i < n1) {
                    if (isdigit(s1[i])) {
                        int num1 = 0;
                        for (int a = i; a < min(n1, i+3) && isdigit(s1[a]); a++) {
                            num1 = num1*10 + (s1[a]-'0');
                            if (dfs(a+1, j, diff+num1)) return res = true;
                        }
                    } else {
                        res = dfs(i+1, j, diff+1);
                    }
                }
            }
            return res;
        };
        
        return dfs(0, 0, 0);
    }
};
