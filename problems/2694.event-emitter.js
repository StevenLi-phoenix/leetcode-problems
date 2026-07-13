// @leetcode id=2694 questionId=2797 slug=event-emitter lang=javascript site=leetcode.com title="Event Emitter"
class EventEmitter {
    constructor() {
        this.listeners = {};
    }

    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        if (!this.listeners[eventName]) this.listeners[eventName] = [];
        const list = this.listeners[eventName];
        list.push(callback);

        return {
            unsubscribe: () => {
                const idx = list.indexOf(callback);
                if (idx !== -1) list.splice(idx, 1);
            }
        };
    }

    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        const list = this.listeners[eventName] || [];
        return list.map(cb => cb(...args));
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */
