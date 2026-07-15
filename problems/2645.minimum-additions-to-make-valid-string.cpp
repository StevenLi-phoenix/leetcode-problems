// @leetcode id=2645 questionId=2736 slug=minimum-additions-to-make-valid-string lang=cpp site=leetcode.com title="Minimum Additions to Make Valid String"
class Solution {
public:
    int addMinimum(string word) {
        int additions = 0;
        int i = 0;
        int n = word.size();
        string abc = "abc";
        while (i < n) {
            for (int j = 0; j < 3; j++) {
                if (i < n && word[i] == abc[j]) {
                    i++;
                } else {
                    additions++;
                }
            }
        }
        return additions;
    }
};
