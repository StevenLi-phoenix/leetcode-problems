// @leetcode id=2648 questionId=2775 slug=generate-fibonacci-sequence lang=javascript site=leetcode.com title="Generate Fibonacci Sequence"
/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let a = 0, b = 1;
    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
