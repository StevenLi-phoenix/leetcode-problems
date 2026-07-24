// @leetcode id=2619 questionId=2734 slug=array-prototype-last lang=javascript site=leetcode.com title="Array Prototype Last"
/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    return this.length === 0 ? -1 : this[this.length - 1];
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */
