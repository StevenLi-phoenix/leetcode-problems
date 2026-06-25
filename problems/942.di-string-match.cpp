// @leetcode id=942 questionId=979 slug=di-string-match lang=cpp site=leetcode.com title="DI String Match"
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> result;
        int low = 0, high = n;

        for (char c : s) {
            if (c == 'I') {
                result.push_back(low);
                low++;
            } else {
                result.push_back(high);
                high--;
            }
        }

        result.push_back(low);
        return result;
    }
};
