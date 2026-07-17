// @leetcode id=2650 questionId=2788 slug=design-cancellable-function lang=javascript site=leetcode.com title="Design Cancellable Function"
/**
 * @param {Generator} generator
 * @return {[Function, Promise]}
 */
var cancellable = function(generator) {
    let finished = false;
    let pendingCancelHandler = null;

    let resolveOuter, rejectOuter;
    const promise = new Promise((resolve, reject) => {
        resolveOuter = resolve;
        rejectOuter = reject;
    });

    function step(fn) {
        if (finished) return;
        let result;
        try {
            result = fn();
        } catch (e) {
            finished = true;
            pendingCancelHandler = null;
            rejectOuter(e);
            return;
        }
        if (result.done) {
            finished = true;
            pendingCancelHandler = null;
            resolveOuter(result.value);
            return;
        }
        let settled = false;
        pendingCancelHandler = () => {
            if (settled || finished) return;
            settled = true;
            pendingCancelHandler = null;
            step(() => generator.throw("Cancelled"));
        };
        result.value.then(
            (v) => {
                if (settled || finished) return;
                settled = true;
                pendingCancelHandler = null;
                step(() => generator.next(v));
            },
            (err) => {
                if (settled || finished) return;
                settled = true;
                pendingCancelHandler = null;
                step(() => generator.throw(err));
            }
        );
    }

    function cancel() {
        if (pendingCancelHandler) pendingCancelHandler();
    }

    step(() => generator.next());

    return [cancel, promise];
};

/**
 * function* tasks() {
 *   const val = yield new Promise(resolve => resolve(2 + 2));
 *   yield new Promise(resolve => setTimeout(resolve, 100));
 *   return val + 1;
 * }
 * const [cancel, promise] = cancellable(tasks());
 * setTimeout(cancel, 50);
 * promise.catch(console.log); // logs "Cancelled" at t=50ms
 */
