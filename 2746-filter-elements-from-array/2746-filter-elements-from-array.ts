function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    return arr.reduce((acc: number[], curr: number, index: number) => {
        if (fn(curr, index)) {
            acc.push(curr);
        }
        return acc;
    }, []);
}