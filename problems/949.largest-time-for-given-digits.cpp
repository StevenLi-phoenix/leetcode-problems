// @leetcode id=949 questionId=986 slug=largest-time-for-given-digits lang=cpp site=leetcode.com title="Largest Time for Given Digits"
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int best = -1;

        do {
            int h = arr[0] * 10 + arr[1];
            int m = arr[2] * 10 + arr[3];
            if (h < 24 && m < 60) {
                best = max(best, h * 60 + m);
            }
        } while (next_permutation(arr.begin(), arr.end()));

        if (best == -1) return "";

        int h = best / 60, m = best % 60;
        string result;
        result += ('0' + h / 10);
        result += ('0' + h % 10);
        result += ':';
        result += ('0' + m / 10);
        result += ('0' + m % 10);
        return result;
    }
};
