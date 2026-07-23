// @leetcode id=2727 questionId=2864 slug=is-object-empty lang=javascript site=leetcode.com title="Is Object Empty"
/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    for (const key in obj) {
        return false;
    }
    return true;
};
