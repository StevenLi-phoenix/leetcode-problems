// @leetcode id=2618 questionId=2758 slug=check-if-object-instance-of-class lang=javascript site=leetcode.com title="Check if Object Instance of Class"
/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if (typeof classFunction !== 'function') return false;
    if (obj === null || obj === undefined) return false;

    const boxed = Object(obj);
    let proto = Object.getPrototypeOf(boxed);
    while (proto !== null) {
        if (proto === classFunction.prototype) return true;
        proto = Object.getPrototypeOf(proto);
    }
    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */
