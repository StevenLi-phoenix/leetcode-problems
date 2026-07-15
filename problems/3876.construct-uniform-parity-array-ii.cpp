// @leetcode id=3876 questionId=4258 slug=construct-uniform-parity-array-ii lang=cpp site=leetcode.com title="Construct Uniform Parity Array II"
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> sorted = nums1;
        sort(sorted.begin(), sorted.end());

        for (int target = 0; target <= 1; target++) {
            bool seenEven = false, seenOdd = false;
            bool ok = true;
            for (int v : sorted) {
                int p = v % 2;
                bool direct = (p == target);
                bool viaSwap = false;
                int q = p ^ target;
                if (q == 0 && seenEven) viaSwap = true;
                if (q == 1 && seenOdd) viaSwap = true;

                if (!direct && !viaSwap) {
                    ok = false;
                    break;
                }
                if (p == 0) seenEven = true;
                else seenOdd = true;
            }
            if (ok) return true;
        }
        return false;
    }
};
