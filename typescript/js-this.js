const obj = {
    msg: 'Hello',
    greet() {
        console.log(this.msg);
    }
}

obj.greet.call({ msg: 'Hi' });

function MyConstructor() {
    this.name = 'ChatGPT';
    
    // 这里我们故意返回一个完全不同的对象
    return {
        specialName: 'Different Object'
    };
}

const instance = new MyConstructor();
console.log(instance.name);         // undefined
console.log(instance.specialName);  // 'Different Object'

function AnotherConstructor() {
    this.name = 'ChatGPT';
    
    // 这里返回一个值类型
    return 42;
}

const anotherInstance = new AnotherConstructor();
console.log(anotherInstance.name);  // 'ChatGPT'
console.log(anotherInstance);       // 输出整个对象，你会发现它没有包含数字42
