class EventEmitter {
    constructor() {
        this.d = new Map();
    }

    subscribe(eventName, callback) {
        if (!this.d.has(eventName)) {
            this.d.set(eventName, new Set());
        }
        this.d.get(eventName).add(callback);

        return {
            unsubscribe: () => {
                this.d.get(eventName)?.delete(callback);
            },
        };
    }

    emit(eventName, args = []) {
        const callbacks = this.d.get(eventName);
        if (!callbacks) {
            return [];
        }
        return [...callbacks].map(callback => callback(...args));
    }
}