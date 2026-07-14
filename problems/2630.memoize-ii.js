// @leetcode id=2630 questionId=2744 slug=memoize-ii lang=javascript site=leetcode.com title="Memoize II"
/**
 * @param {Function} fn
 * @return {Function}
 */
const VALUE_KEY = Symbol('value');

function memoize(fn) {
    const root = new Map();

    return function(...args) {
        let node = root;
        for (const arg of args) {
            if (!node.has(arg)) node.set(arg, new Map());
            node = node.get(arg);
        }
        if (!node.has(VALUE_KEY)) {
            node.set(VALUE_KEY, fn(...args));
        }
        return node.get(VALUE_KEY);
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
