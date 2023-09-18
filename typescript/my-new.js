function myNew(ctor, ...args) {
    let fn = Array.prototype.shift.call(arguments)
    if (typeof fn !== 'function') throw `${fn} is not a constructor`
    let obj = Object.create(fn.prototype)
    let res = fn.apply(obj, args)
    let isObject = typeof res === 'object' && res !== null
    let isFunction = typeof res === 'function'
    return isObject || isFunction ? res: obj
}

const one = myNew(1);
console.log(one)