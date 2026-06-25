// @leetcode id=2185 questionId=2292 slug=counting-words-with-a-given-prefix lang=cpp site=leetcode.com title="Counting Words With a Given Prefix"
class Solution {
    public:
        int prefixCount(vector<string>& words, string pref) {
                int count = 0;
                        for (auto& w : words) {
                                    if (w.find(pref) == 0) count++;
                                            }
                                                    return count;
                                                        }
            };
