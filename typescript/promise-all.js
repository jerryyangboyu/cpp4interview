Promise.myAll = function (promises) {
    return new Promise((resolve, reject) => {
        if (!Array.isArray(promises)) {
            return reject(new TypeError('arguments must be an array'));
        }

        let resolvedCounter = 0;
        let promiseNum = promises.length;
        let promiseResult = []

        for (let i = 0; i < promiseNum; i++) {
            Promise.resolve(promises[i])
                .then((value) => {
                    resolvedCounter++;
                    promiseResult[i] = value;
                    if (resolvedCounter === promiseNum) {
                        return resolve(promiseResult);
                    }
                })
                .catch((reason) => {
                    return reject(reason);
                })
        }
    })
}