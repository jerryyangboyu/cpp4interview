const 睡觉 = (睡觉时间) =>
    new Promise((反馈回调) =>
        setTimeout(
            () => 反馈回调(), 睡觉时间
        )
    )


睡觉(3000).then(() => {
    console.log("睡晚了")
})