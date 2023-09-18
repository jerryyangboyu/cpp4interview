class EventBus {
    listeners: Map<string, Array<Function>>;

    constructor() {
        this.listeners = new Map()
    }

    on(event: string, callback: Function) {
        if (!this.listeners.has(event)) {
            this.listeners.set(event, []);
        }
        this.listeners.get(event).push(callback);
    }

    emit(event: string, ...args: unknown[]) {
        if (!this.listeners.has(event)) {
            throw new Error(`No event with name ${event} was registered.`);
        }
        this.listeners.get(event).forEach((cb) => {
            cb(...args);
        })
    }

    off(event: string, callback: Function) {
        if (!this.listeners.has(event)) {
            throw new Error(`No event with name ${event} was registered.`);
        }
        this.listeners.set(event, this.listeners
            .get(event)
            .filter((cb) => cb !== callback))
    }

    offAll(event: string) {
        if (!this.listeners.has(event)) {
            throw new Error(`No event with name ${event} was registered.`);
        }
        this.listeners.delete(event);
    }

    once(event: string, callback: Function) {
        const onceCallback = (...args: unknown[]) => {
            callback(...args);
            this.off(event, onceCallback);
        }
        this.on(event, onceCallback)
    }
}
