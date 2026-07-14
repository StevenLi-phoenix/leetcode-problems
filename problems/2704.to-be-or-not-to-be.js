// @leetcode id=2704 questionId=2813 slug=to-be-or-not-to-be lang=javascript site=leetcode.com title="To Be Or Not To Be"
/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe: function(other) {
            if (val === other) return true;
            throw new Error("Not Equal");
        },
        notToBe: function(other) {
            if (val !== other) return true;
            throw new Error("Equal");
        }
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
