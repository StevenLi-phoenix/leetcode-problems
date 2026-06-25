// @leetcode id=1668 questionId=1764 slug=maximum-repeating-substring lang=cpp site=leetcode.com title="Maximum Repeating Substring"
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        string repeated = word;
        while (sequence.find(repeated) != string::npos) {
            k++;
            repeated += word;
        }
        return k;
    }
};
