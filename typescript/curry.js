const curry = fn => 
    judge = (...args) => 
        args.length === fn.length
            ? fn(...args)
            : (arg2) => judge(...args, arg2)


const add = (x, y) => x + y
console.log(curry(add)(1)(2))
