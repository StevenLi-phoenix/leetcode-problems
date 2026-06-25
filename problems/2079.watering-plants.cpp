// @leetcode id=2079 questionId=1310 slug=watering-plants lang=cpp site=leetcode.com title="Watering Plants"
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int water = capacity;
        int pos = -1; // start at river x=-1
        
        for (int i = 0; i < (int)plants.size(); i++) {
            if (water < plants[i]) {
                // Need to refill: go back to river (pos - (-1) steps = pos+1)
                // Then go from river to plant i (i - (-1) = i+1 steps)
                steps += (pos + 1) + (i + 1); // back to river + river to plant i
                water = capacity - plants[i];
                pos = i;
            } else {
                // Just walk from pos to plant i
                steps += (i - pos);
                water -= plants[i];
                pos = i;
            }
        }
        return steps;
    }
};
