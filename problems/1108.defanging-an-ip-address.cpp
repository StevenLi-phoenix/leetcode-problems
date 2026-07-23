// @leetcode id=1108 questionId=1205 slug=defanging-an-ip-address lang=cpp site=leetcode.com title="Defanging an IP Address"
class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for (char c : address) {
            if (c == '.') result += "[.]";
            else result += c;
        }
        return result;
    }
};
