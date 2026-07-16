// @leetcode id=2721 questionId=2807 slug=execute-asynchronous-functions-in-parallel lang=javascript site=leetcode.com title="Execute Asynchronous Functions in Parallel"
/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const results = new Array(functions.length);
        let remaining = functions.length;
        if (remaining === 0) {
            resolve(results);
            return;
        }
        functions.forEach((fn, i) => {
            fn().then((value) => {
                results[i] = value;
                remaining--;
                if (remaining === 0) resolve(results);
            }).catch((err) => {
                reject(err);
            });
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
