Function.prototype.myBind = function() {
    if (typeof this !== 'function') throw 'caller must be a function'
    let self = this
    let context = arguments[0]
    let args = Array.prototype.slice.call(arguments, 1)
    let fn = function() {
        let fnArgs = Array.prototype.slice.call(arguments)
        self.apply(this instanceof self ? this: context, args.concat(fnArgs))
    }
    fn.prototype = Object.create(self.prototype)
    return fn
}