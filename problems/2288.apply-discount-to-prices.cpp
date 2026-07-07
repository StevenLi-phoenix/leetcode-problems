// @leetcode id=2288 questionId=2373 slug=apply-discount-to-prices lang=cpp site=leetcode.com title="Apply Discount to Prices"
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) words.push_back(word);

        for (string& w : words) {
            if (w.size() < 2 || w[0] != '$') continue;
            bool allDigits = true;
            for (int i = 1; i < (int)w.size(); ++i) {
                if (!isdigit(w[i])) { allDigits = false; break; }
            }
            if (!allDigits) continue;

            long long value = stoll(w.substr(1));
            long long discountedCents = value * (100 - discount);
            long long dollars = discountedCents / 100;
            long long cents = discountedCents % 100;

            string centsStr = to_string(cents);
            if (centsStr.size() < 2) centsStr = "0" + centsStr;

            w = "$" + to_string(dollars) + "." + centsStr;
        }

        string result;
        for (int i = 0; i < (int)words.size(); ++i) {
            if (i > 0) result += " ";
            result += words[i];
        }
        return result;
    }
};
