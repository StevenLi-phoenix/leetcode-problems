// @leetcode id=2624 questionId=2760 slug=snail-traversal lang=javascript site=leetcode.com title="Snail Traversal"
/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    if (rowsCount * colsCount !== this.length) return [];
    const result = Array.from({ length: rowsCount }, () => new Array(colsCount));
    let idx = 0;
    for (let c = 0; c < colsCount; c++) {
        if (c % 2 === 0) {
            for (let r = 0; r < rowsCount; r++) result[r][c] = this[idx++];
        } else {
            for (let r = rowsCount - 1; r >= 0; r--) result[r][c] = this[idx++];
        }
    }
    return result;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */
