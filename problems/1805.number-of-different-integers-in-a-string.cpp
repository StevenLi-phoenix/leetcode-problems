// @leetcode id=1805 questionId=1933 slug=number-of-different-integers-in-a-string lang=cpp site=leetcode.com title="Number of Different Integers in a String"
class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> nums;
        int n = word.size();
        int i = 0;
        while (i < n) {
            if (isdigit(word[i])) {
                // Skip leading zeros
                while (i < n && word[i] == '0') i++;
                string num = "";
                while (i < n && isdigit(word[i])) {
                    num += word[i++];
                }
                nums.insert(num);
            } else {
                i++;
            }
        }
        return nums.size();
    }
};
