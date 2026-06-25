// @leetcode id=2167 questionId=2286 slug=minimum-time-to-remove-all-cars-containing-illegal-goods lang=cpp site=leetcode.com title="Minimum Time to Remove All Cars Containing Illegal Goods"
class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();
        // left[i] = min cost to remove all '1's in s[0..i]
        // using type 1 (left removal) and type 3 (middle removal)
        vector<int> left(n, 0);
        if (s[0] == '1') left[0] = 1; // remove from left end costs 1
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                left[i] = left[i-1];
            } else {
                // Option 1: remove this car from middle (+2)
                // Option 2: remove entire prefix (i+1 cars from left, costs i+1)
                left[i] = min(left[i-1] + 2, i + 1);
            }
        }
        
        // right[i] = min cost to remove all '1's in s[i..n-1]
        // using type 2 (right removal) and type 3 (middle removal)
        vector<int> right(n, 0);
        if (s[n-1] == '1') right[n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            if (s[i] == '0') {
                right[i] = right[i+1];
            } else {
                // Option 1: remove this car from middle (+2)
                // Option 2: remove entire suffix (n-i cars from right, costs n-i)
                right[i] = min(right[i+1] + 2, n - i);
            }
        }
        
        // Answer: min over all split points
        // Either use only left[n-1] (remove everything from left+middle)
        // Or only right[0] (remove everything from right+middle)
        // Or split: left[i] + right[i+1]
        int ans = min(left[n-1], right[0]);
        for (int i = 0; i < n-1; i++) {
            ans = min(ans, left[i] + right[i+1]);
        }
        return ans;
    }
};
