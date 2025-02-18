type Fn = (accum: number, curr: number) => number;

function reduce(nums: number[], fn: Fn, init: number): number {
    if (nums.length === 0) {
        return init;
    }

    const [first, ...rest] = nums;
    return reduce(rest, fn, fn(init, first));
}