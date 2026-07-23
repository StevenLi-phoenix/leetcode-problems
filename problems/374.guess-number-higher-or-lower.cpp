// @leetcode id=374 questionId=374 slug=guess-number-higher-or-lower lang=cpp site=leetcode.com title="Guess Number Higher or Lower"
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long lo = 1, hi = n;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            int res = guess((int)mid);
            if (res == 0) return (int)mid;
            else if (res < 0) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};
