// @leetcode id=2703 questionId=2820 slug=return-length-of-arguments-passed lang=javascript site=leetcode.com title="Return Length of Arguments Passed"
/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    return args.length;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */
