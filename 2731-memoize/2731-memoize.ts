type Fn = (...params: any) => any;

function memoize(fn: Fn): Fn {
    const cache = new Map<string, any>();

    return function (...args: any[]) {
        const key = JSON.stringify(args);

        if (cache.has(key)) {
            return cache.get(key);
        }

        const result = fn(...args);
        cache.set(key, result);
        return result;
    };
}

/**
 * Example usage:
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *   callCount += 1;
 *   return a + b;
 * });
 * console.log(memoizedFn(2, 3)); // 5
 * console.log(memoizedFn(2, 3)); // 5 (cached)
 * console.log(callCount); // 1
 */