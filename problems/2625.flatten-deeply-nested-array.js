// @leetcode id=2625 questionId=2759 slug=flatten-deeply-nested-array lang=javascript site=leetcode.com title="Flatten Deeply Nested Array"
/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    const result = [];
    for (const item of arr) {
        if (Array.isArray(item) && n > 0) {
            result.push(...flat(item, n - 1));
        } else {
            result.push(item);
        }
    }
    return result;
};
