function cancellable(fn, args, t) {
    fn(...args);

    const time = setInterval(() => fn(...args), t);

    return () => clearInterval(time);
}

/**
 * Example usage:
 */
const result = [];

const fn = (x) => x * 2;
const args = [4], t = 20, cancelT = 110;

const log = (...argsArr) => {
    result.push({ time: Date.now(), returned: fn(...argsArr) });
};

const cancel = cancellable(log, args, t);

setTimeout(() => {
    cancel();
    console.log(result); // [
                         //      {"time":0,"returned":8},
                         //      {"time":20,"returned":8},
                         //      {"time":40,"returned":8},
                         //      {"time":60,"returned":8},
                         //      {"time":80,"returned":8},
                         //      {"time":100,"returned":8}
                         //  ]
}, cancelT);