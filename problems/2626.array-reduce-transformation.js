// @leetcode id=2626 questionId=2761 slug=array-reduce-transformation lang=javascript site=leetcode.com title="Array Reduce Transformation"
/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let val = init;
    for (const num of nums) {
        val = fn(val, num);
    }
    return val;
};
