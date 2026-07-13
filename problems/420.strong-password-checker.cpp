// @leetcode id=420 questionId=420 slug=strong-password-checker lang=cpp site=leetcode.com title="Strong Password Checker"
class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        int missingLower = 1, missingUpper = 1, missingDigit = 1;
        for (char c : password) {
            if (islower((unsigned char)c)) missingLower = 0;
            else if (isupper((unsigned char)c)) missingUpper = 0;
            else if (isdigit((unsigned char)c)) missingDigit = 0;
        }
        int missing = missingLower + missingUpper + missingDigit;

        vector<int> runs;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && password[j] == password[i]) j++;
            int len = j - i;
            if (len >= 3) runs.push_back(len);
            i = j;
        }

        if (n < 6) {
            return max(missing, 6 - n);
        } else if (n <= 20) {
            int replace = 0;
            for (int r : runs) replace += r / 3;
            return max(missing, replace);
        } else {
            int del = n - 20;
            int totalReplace = 0;
            for (int r : runs) totalReplace += r / 3;

            int remainingDel = del;
            // Deleting from a run with length % 3 == 0 saves one replacement
            // per single deletion (cheapest); handle those first.
            for (size_t idx = 0; idx < runs.size() && remainingDel > 0; idx++) {
                if (runs[idx] % 3 == 0) {
                    runs[idx] -= 1;
                    remainingDel -= 1;
                    totalReplace -= 1;
                }
            }
            // length % 3 == 1 runs need two deletions to save one replacement.
            for (size_t idx = 0; idx < runs.size() && remainingDel >= 2; idx++) {
                if (runs[idx] % 3 == 1) {
                    runs[idx] -= 2;
                    remainingDel -= 2;
                    totalReplace -= 1;
                }
            }
            // Any leftover deletions save one replacement per three deletions
            // regardless of which run they land on.
            totalReplace -= remainingDel / 3;
            if (totalReplace < 0) totalReplace = 0;

            return del + max(missing, totalReplace);
        }
    }
};
