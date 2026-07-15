// @leetcode id=2705 questionId=2804 slug=compact-object lang=javascript site=leetcode.com title="Compact Object"
/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        return obj
            .map(compactObject)
            .filter(Boolean);
    }
    if (obj !== null && typeof obj === 'object') {
        const result = {};
        for (const key in obj) {
            const value = compactObject(obj[key]);
            if (value) {
                result[key] = value;
            }
        }
        return result;
    }
    return obj;
};
