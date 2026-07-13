// @leetcode id=3823 questionId=4200 slug=reverse-letters-then-special-characters-in-a-string lang=cpp site=leetcode.com title="Reverse Letters Then Special Characters in a String"
class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && !islower(s[i])) i++;
            while (i < j && !islower(s[j])) j--;
            if (i < j) swap(s[i++], s[j--]);
        }

        i = 0; j = n - 1;
        while (i < j) {
            while (i < j && islower(s[i])) i++;
            while (i < j && islower(s[j])) j--;
            if (i < j) swap(s[i++], s[j--]);
        }
        return s;
    }
};
