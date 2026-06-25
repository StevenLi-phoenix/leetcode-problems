// @leetcode id=3280 questionId=3567 slug=convert-date-to-binary lang=cpp site=leetcode.com title="Convert Date to Binary"
class Solution {
public:
    string convertDateToBinary(string date) {
        // date format: yyyy-mm-dd
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        auto toBinary = [](int n) -> string {
            if (n == 0) return "0";
            string res = "";
            while (n > 0) {
                res = (char)('0' + (n & 1)) + res;
                n >>= 1;
            }
            return res;
        };
        
        return toBinary(year) + "-" + toBinary(month) + "-" + toBinary(day);
    }
};
