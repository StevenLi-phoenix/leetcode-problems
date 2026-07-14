// @leetcode id=2105 questionId=2228 slug=watering-plants-ii lang=cpp site=leetcode.com title="Watering Plants II"
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i = 0, j = plants.size() - 1;
        long long a = capacityA, b = capacityB;
        int refills = 0;

        while (i < j) {
            if (a < plants[i]) { refills++; a = capacityA; }
            a -= plants[i++];

            if (b < plants[j]) { refills++; b = capacityB; }
            b -= plants[j--];
        }

        if (i == j) {
            if (max(a, b) < plants[i]) refills++;
        }
        return refills;
    }
};
