// @leetcode id=273 questionId=273 slug=integer-to-english-words lang=cpp site=leetcode.com title="Integer to English Words"
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        static const vector<string> below20 = {
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };
        static const vector<string> tens = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
        };
        static const vector<pair<int, string>> scales = {
            {1'000'000'000, "Billion"}, {1'000'000, "Million"}, {1'000, "Thousand"}
        };

        function<string(int)> threeDigits = [&](int n) -> string {
            string result;
            if (n >= 100) {
                result += below20[n / 100] + " Hundred";
                n %= 100;
                if (n > 0) result += " ";
            }
            if (n >= 20) {
                result += tens[n / 10];
                if (n % 10 > 0) result += " " + below20[n % 10];
            } else if (n > 0) {
                result += below20[n];
            }
            return result;
        };

        string result;
        for (auto& [scale, name] : scales) {
            if (num >= scale) {
                result += threeDigits(num / scale) + " " + name + " ";
                num %= scale;
            }
        }
        if (num > 0) result += threeDigits(num);
        while (!result.empty() && result.back() == ' ') result.pop_back();
        return result;
    }
};
