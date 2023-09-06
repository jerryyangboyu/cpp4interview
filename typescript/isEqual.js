function isEqual(obj1, obj2) {
    let isObj = toString.call(obj1) === '[object Object]' && toString.call(obj2) === '[object Object]';
    if (!isObj) {
        return false
    }

    let obj1Keys = Object.keys(obj1);
    let obj2Keys = Object.keys(obj2);
    if (obj1Keys.length !== obj2Keys.length) {
        return false
    }

    for (const key in obj1) {
        // 判断两个对象的键是否相等
        if (obj2.hasOwnProperty(key)) {
            let obj1Type = toString.call(obj1[key]);
            let obj2Type = toString.call(obj2[key]);
            // 如果值是对象，则递归
            if (obj1Type === '[object Object]' || obj2Type === '[object Object]') {
                if (!isEqual(obj1[key], obj2[key])) {
                    return false;
                }
            } else if (obj1[key] !== obj2[key]) {
                return false; // 如果不是对象，则判断值是否相等
            }
        } else {
            return false;
        }
    }
}