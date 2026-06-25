// @leetcode id=2483 questionId=2576 slug=minimum-penalty-for-a-shop lang=cpp site=leetcode.com title="Minimum Penalty for a Shop"
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = (int)customers.size();

        // penalty if we close at hour 0: all 'Y' are missed while closed
        int penalty = 0;
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }

        int bestHour = 0;
        int bestPenalty = penalty;

        // Move closing time from j to j+1 by processing hour j as "open"
        for (int j = 0; j < n; j++) {
            if (customers[j] == 'Y') penalty -= 1; // saved a missed customer
            else penalty += 1;                     // open with no customer

            // closing at hour (j+1)
            int closeHour = j + 1;
            if (penalty < bestPenalty) {
                bestPenalty = penalty;
                bestHour = closeHour;
            }
            // if equal, keep earliest (do nothing)
        }

        return bestHour;
    }
};
