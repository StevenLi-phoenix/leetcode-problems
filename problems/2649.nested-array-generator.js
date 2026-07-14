// @leetcode id=2649 questionId=2783 slug=nested-array-generator lang=javascript site=leetcode.com title="Nested Array Generator"
/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function*(arr) {
    for (const el of arr) {
        if (Array.isArray(el)) {
            yield* inorderTraversal(el);
        } else {
            yield el;
        }
    }
};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */
