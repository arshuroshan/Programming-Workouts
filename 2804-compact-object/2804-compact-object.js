var compactObject = function (obj) {
    if (!obj || typeof obj !== 'object') {
        return obj;
    }

    if (Array.isArray(obj)) {
        const result = [];
        for (const item of obj) {
            const compactedItem = compactObject(item);
            if (compactedItem) {
                result.push(compactedItem);
            }
        }
        return result;
    }

    const result = {};
    for (const key in obj) {
        if (obj.hasOwnProperty(key)) {
            const compactedValue = compactObject(obj[key]);
            if (compactedValue) {
                result[key] = compactedValue;
            }
        }
    }
    return result;
};