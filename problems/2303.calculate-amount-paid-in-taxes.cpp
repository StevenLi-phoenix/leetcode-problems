// @leetcode id=2303 questionId=1382 slug=calculate-amount-paid-in-taxes lang=cpp site=leetcode.com title="Calculate Amount Paid in Taxes"
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0.0;
        int prev = 0;
        for (auto& b : brackets) {
            int upper = b[0];
            int percent = b[1];
            if (income <= prev) break;
            int taxable = min(income, upper) - prev;
            tax += taxable * percent / 100.0;
            prev = upper;
        }
        return tax;
    }
};
