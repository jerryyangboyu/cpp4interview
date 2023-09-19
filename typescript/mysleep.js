function sleep(ms) {
    return new Promise((resolve) => setTimeout(resolve, ms))
}

async function main() {
    console.log('Hello1')
    await sleep(3000)
    console.log('Hello2')
}

main()