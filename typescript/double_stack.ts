const evaluate = (s: string): number => {
    const m = new Map<string, number>()
    m.set('+', 1)
    m.set('-', 1)
    m.set('*', 2)
    m.set('/', 2)
    m.set('%', 2)
    m.set('^', 3)

    const nums: number[] = [0]
    const ops: string[] = []

    const doCalculate = () => {
        const b = nums.pop()
        const a = nums.pop()
        let ans = 0
        const op = ops.pop()

        switch (op) {
            case '+': ans = a + b; break
            case '-': ans = a - b; break
            case '*': ans = a * b; break
            case '/': ans = a / b; break
            case '%': ans = a % b; break
            case '^': ans = a ^ b; break
        }

        nums.push(ans)
    }

    s = s.replace(/\s+/g, "")
        .replace(/\(-/g, "(0-")
        .replace(/\(\+/g, "(")

    const digitExpression = /^\d$/

    for (let i = 0; i < s.length; i++) {
        const ch = s[i]

        if (digitExpression.test(ch)) {
            let num = 0
            while (i < s.length && digitExpression.test(s[i])) {
                num = num * 10 + parseInt(s[i++])
            }
            i--
            nums.push(num)
        }

        else if (m.has(ch)) {
            while (ops.length !== 0 && m.has(ops[ops.length - 1]) && m.get(ops[ops.length - 1]) >= m.get(ch)) {
                doCalculate()
            }
            ops.push(ch)
        }

        else if (ch === '(') {
            ops.push(ch)
        }

        else if (ch === ')') {
            while (ops.length !== 0 && ops[ops.length - 1] !== '(') {
                doCalculate()
            }
            ops.pop() // pop '('
        }

        else {
            throw new Error(`Unexpected character: ${ch}`)
        }
    }

    while (ops.length !== 0) {
        doCalculate()
    }

    return nums.pop()
}

console.log(evaluate("4 * 2 + 3"))
console.log(evaluate("4 * (2 + 3)"))
console.log(evaluate("4 * (2 + 3) + 1"))
console.log(evaluate("4 * (2 + 3) + 1 * 2"))
