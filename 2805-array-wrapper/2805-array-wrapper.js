class ArrayWrapper {
    constructor(nums) {
        this.nums = nums;
        this.s = nums.reduce((a, b) => a + b, 0);
    }

    valueOf() {
        return this.s;
    }

    toString() {
        return `[${this.nums}]`;
    }
}