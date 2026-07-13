// @leetcode id=2631 questionId=2742 slug=group-by lang=javascript site=leetcode.com title="Group By"
/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const result = {};
    for (const item of this) {
        const key = fn(item);
        if (!result[key]) result[key] = [];
        result[key].push(item);
    }
    return result;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
