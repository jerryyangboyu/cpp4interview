function myInstanceof(obj, cls) {
    if (typeof obj !== 'object' || obj === null) return false;
    
    let obj_proto = Object.getPrototypeOf(obj);
    let cls_proto = cls.prototype;

    while (obj_proto !== null) {
        if (obj_proto === cls_proto) return true;
        obj_proto = Object.getPrototypeOf(obj_proto);
    }

    return false;
}

class A {}

console.log(myInstanceof(new Object(), A))
