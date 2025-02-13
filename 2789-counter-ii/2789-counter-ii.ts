class Counter {
    private val: number;
    private init: number;

    constructor(init: number) {
        this.val = init;
        this.init = init;
    }

    increment(): number {
        return ++this.val;
    }

    decrement(): number {
        return --this.val;
    }

    reset(): number {
        this.val = this.init;
        return this.val;
    }
}

function createCounter(init: number): ReturnObj {
    return new Counter(init);
}

type ReturnObj = {
    increment: () => number;
    decrement: () => number;
    reset: () => number;
};

// Example usage:
const counter = createCounter(5);
console.log(counter.increment());
console.log(counter.reset());
console.log(counter.decrement());