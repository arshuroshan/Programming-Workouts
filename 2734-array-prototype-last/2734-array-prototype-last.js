// Extend the Array prototype with a 'last' method
Array.prototype.last = function () {
    return this.length ? this[this.length - 1] : -1;
};

const arr = [1, 2, 3];
console.log(arr.last());

const emptyArr = [];
console.log(emptyArr.last());