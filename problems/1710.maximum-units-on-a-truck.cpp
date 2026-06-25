// @leetcode id=1710 questionId=1829 slug=maximum-units-on-a-truck lang=cpp site=leetcode.com title="Maximum Units on a Truck"
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        int totalUnits = 0;
        int boxesUsed = 0;

        for (auto& box : boxTypes) {
            int count = min(box[0], truckSize - boxesUsed);
            totalUnits += count * box[1];
            boxesUsed += count;

            if (boxesUsed == truckSize) break;
        }

        return totalUnits;
    }
};
