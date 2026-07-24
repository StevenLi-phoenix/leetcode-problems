// @leetcode id=2667 questionId=2809 slug=create-hello-world-function lang=javascript site=leetcode.com title="Create Hello World Function"
/**
 * @return {Function}
 */
var createHelloWorld = function() {
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
