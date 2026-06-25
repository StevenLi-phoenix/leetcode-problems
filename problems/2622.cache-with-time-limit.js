// @leetcode id=2622 questionId=2762 slug=cache-with-time-limit lang=javascript site=leetcode.com title="Cache With Time Limit"
var TimeLimitedCache = function() {
    this.cache = new Map(); // key -> {value, expireTime}
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const now = Date.now();
    const existed = this.cache.has(key) && this.cache.get(key).expireTime > now;
    this.cache.set(key, { value, expireTime: now + duration });
    return existed;
};

/**
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    const now = Date.now();
    if (this.cache.has(key) && this.cache.get(key).expireTime > now) {
        return this.cache.get(key).value;
    }
    return -1;
};

/**
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    const now = Date.now();
    let cnt = 0;
    for (const [key, entry] of this.cache) {
        if (entry.expireTime > now) cnt++;
    }
    return cnt;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */
