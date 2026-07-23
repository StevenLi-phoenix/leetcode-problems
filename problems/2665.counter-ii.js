// @leetcode id=2665 questionId=2789 slug=counter-ii lang=javascript site=leetcode.com title="Counter II"
/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let current = init;
    return {
        increment: () => ++current,
        decrement: () => --current,
        reset: () => (current = init),
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
