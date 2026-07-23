// @leetcode id=2469 questionId=2556 slug=convert-the-temperature lang=cpp site=leetcode.com title="Convert the Temperature"
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.80 + 32.00};
    }
};
