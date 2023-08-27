// same file registration
const s1 = Symbol()
const s2 = Symbol()
console.log(s1 === s2) // false

const namedSymbol = Symbol('symbol name')
console.log(namedSymbol.description) // Symbol(name)

// symbol used to represent properties of an object that is not exposed to the code
const SpecialAPI = {
    [namedSymbol]: "This is a private value",
    publicValue: "This is a public value"
}
console.log(SpecialAPI[namedSymbol]) // This is a private value
console.log(Object.keys(SpecialAPI)) // ["publicValue"]
console.log(Object.getOwnPropertyNames(SpecialAPI)) // ["publicValue"]
console.log(Object.getOwnPropertySymbols(SpecialAPI)) // [Symbol(symbol name)]

const iterable_arr = [1, 2, 3]
console.log(iterable_arr.keys()) // Object [Array Iterator] {}
const iterator = iterable_arr[Symbol.iterator]()
console.log(iterator.next()) // { value: 1, done: false }

// Global symbol registry
// file1.js
const s3 = Symbol.for('global symbol')
// file2.js
const s4 = Symbol.for('global symbol')
console.log(s3 === s4) // true
