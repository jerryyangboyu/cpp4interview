Function.prototype.myCall = function () {
    if (typeof this !== 'function') throw 'caller must be a function'
    let self = arguments[0] || window
    self._fn = this
    let args = [...arguments].flat().slice(1)
    let res = self._fn(...args)
    Reflect.deleteProperty(self, '_fn')
    return res
}

function add(a, b) { return this.a + b };

console.log(add.myCall({a: 3}, 4, 5))
