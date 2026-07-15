// @leetcode id=3514 questionId=3820 slug=number-of-unique-xor-triplets-ii lang=cpp site=leetcode.com title="Number of Unique XOR Triplets II"
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int RANGE = 2048;
        vector<bool> present(RANGE, false);
        for (int x : nums) present[x] = true;

        vector<int> uniqueVals;
        for (int v = 0; v < RANGE; v++) if (present[v]) uniqueVals.push_back(v);

        vector<bool> s2(RANGE, false);
        for (size_t i = 0; i < uniqueVals.size(); i++) {
            for (size_t j = i; j < uniqueVals.size(); j++) {
                s2[uniqueVals[i] ^ uniqueVals[j]] = true;
            }
        }

        vector<int> s2Vals;
        for (int v = 0; v < RANGE; v++) if (s2[v]) s2Vals.push_back(v);

        vector<bool> s3(RANGE, false);
        for (int a : s2Vals) {
            for (int b : uniqueVals) {
                s3[a ^ b] = true;
            }
        }

        int count = 0;
        for (bool b : s3) if (b) count++;
        return count;
    }
};
