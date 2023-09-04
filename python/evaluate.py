nums = []
ops = []

inp = input("Enter the expression: ")
i = 0
while i < len(inp):
    c = inp[i]
    if c == ' ':
        continue
    if c.isdigit():
        nums.append(int(c))
    elif c == '(':
        s = ""
        while c != ')':
            i += 1
            c = inp[i]
            s += c
        ops.append(c)


def evaluate(nums, ops):
    op = ops.pop()
    if op == '*' or op == '/':
        num1 = nums.pop()
        num2 = nums.pop()
        if op == '*':
            nums.append(num1 * num2)
        else:
            nums.append(num1 / num2)
    else:
        num1 = evaluate(nums, ops)
        num2 = evaluate(nums, ops)
        if op == '+':
            nums.append(num1 + num2)
        else:
            nums.append(num1 - num2)
