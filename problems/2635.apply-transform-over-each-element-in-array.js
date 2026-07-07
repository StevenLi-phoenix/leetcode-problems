// @leetcode id=2635 questionId=2747 slug=apply-transform-over-each-element-in-array lang=javascript site=leetcode.com title="Apply Transform Over Each Element in Array"
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const result = [];
    for (let i = 0; i < arr.length; i++) {
        result.push(fn(arr[i], i));
    }
    return result;
};
