// Q1. Multiplication Table generator
function printTable(num) {
    for (let i = 1; i <= 10; i++) {
        console.log(`${num} x ${i} = ${num * i}`);
    }
}



// Q2. Count digits in a number

function coutDigits(num) {
    let count = 0;
    while (num !== 0) {
        num = Math.floor(num / 10);
        count++;
    }
    return count;
}


// Q3. Reverse a String
function reverseString(str) {
    let reversed = '';
    for (let i = str.length - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}



// Q4. Sum of numbers divisible by 3 or 5

function sumDivisible(limit) {
    let sum = 0;
    for (let i = 1; i <= limit; i++) {
        if (i % 3 === 0 || i % 5 === 0) {
            sum += i;
        }
    }
    return sum;
}


// -----------------------------------------
// part B: output based question (Hoisting)

// Q1. Variable Hoisting
console.log(a)
var a = 10

// output 
// undefined


// Q2. Let & Const Hoisting
console.log(b)
let b = 20

// output 
// ReferenceError: cannot access 'b' befor initialization



// Q3. Function Declaration vs Function Expression

sayHello();

function sayHello() {
    console.log("Hello from declaration!");
}

sayHi();

var sayHi = function () {
    console.log("Hello from expression!");
};

// output
// Hello from declaration!
// TypeError: sayHi is not a function 



// Q4. Arrow function Hoisting
greet();

const greet = () => {
    console.log("Hi there!");
};

// output
// ReferenceError: greet is not defind


// Q5. Mixing var and let

console.log(x);
var x = 5;

console.log(y);
let y = 10;

// output
// undefined
// ReferenceError: y is not defined





