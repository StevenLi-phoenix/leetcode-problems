// @leetcode id=2620 questionId=2732 slug=counter lang=javascript site=leetcode.com title="Counter"
/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let current = n;
    return function() {
        return current++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
