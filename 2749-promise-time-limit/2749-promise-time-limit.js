/**
 * @param {Function} fn - The function to be executed with a time limit.
 * @param {number} t - The time limit in milliseconds.
 * @return {Function} - A new function that applies the time limit to `fn`.
 */
function timeLimit(fn, t) {
    return async function (...args) {
        return Promise.race([
            fn(...args),
            new Promise((_, reject) => 
                setTimeout(() => reject('Time Limit Exceeded'), t)
            ),
        ]);
    };
}

/**
 * Example usage:
 */
const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
limited(150).catch(console.log);