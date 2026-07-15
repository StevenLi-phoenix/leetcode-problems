// @leetcode id=2637 questionId=2749 slug=promise-time-limit lang=javascript site=leetcode.com title="Promise Time Limit"
/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    
    return async function(...args) {
        const timeout = new Promise((_, reject) => {
            setTimeout(() => reject("Time Limit Exceeded"), t);
        });
        return Promise.race([fn(...args), timeout]);
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */
