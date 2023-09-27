const 节流 = (控制函数, 时间间隔) => {
    let 时间控制器
    return function() {
        const 上下文 = this
        const 对象函数参数 = arguments
        if (时间控制器 != null) {
            时间控制器 = setTimeout(() => {
                控制函数.apply(上下文, 对象函数参数)
                时间控制器 = null
            }, 时间间隔)
        }
    }
}