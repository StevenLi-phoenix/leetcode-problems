// @leetcode id=3219 questionId=3500 slug=minimum-cost-for-cutting-cake-ii lang=cpp site=leetcode.com title="Minimum Cost for Cutting Cake II"
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());

        long long horizontalPieces = 1, verticalPieces = 1;
        long long cost = 0;
        int i = 0, j = 0;

        while (i < (int)horizontalCut.size() && j < (int)verticalCut.size()) {
            if (horizontalCut[i] >= verticalCut[j]) {
                cost += (long long)horizontalCut[i] * verticalPieces;
                horizontalPieces++;
                i++;
            } else {
                cost += (long long)verticalCut[j] * horizontalPieces;
                verticalPieces++;
                j++;
            }
        }

        while (i < (int)horizontalCut.size()) {
            cost += (long long)horizontalCut[i] * verticalPieces;
            horizontalPieces++;
            i++;
        }

        while (j < (int)verticalCut.size()) {
            cost += (long long)verticalCut[j] * horizontalPieces;
            verticalPieces++;
            j++;
        }

        return cost;
    }
};
