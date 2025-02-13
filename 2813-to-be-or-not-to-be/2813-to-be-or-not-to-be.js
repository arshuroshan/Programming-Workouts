class Expect {
    constructor(val) {
        this.val = val;
    }

    toBe(expected) {
        if (this.val !== expected) {
            throw new Error('Not Equal');
        }
        return true;
    }

    notToBe(expected) {
        if (this.val === expected) {
            throw new Error('Equal');
        }
        return true;
    }
}

/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
    return new Expect(val);
};

try {
    console.log(expect(5).toBe(5));
} catch (e) {
    console.error(e.message);
}

try {
    console.log(expect(5).notToBe(5));
} catch (e) {
    console.error(e.message);
}