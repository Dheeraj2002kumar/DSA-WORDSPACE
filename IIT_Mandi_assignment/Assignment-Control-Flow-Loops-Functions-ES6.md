Sure! Here's your assignment broken down with clear explanations and full solutions for **Part A** and **Part B**:

---

## 📘 **Part A: Function Writing Problems**

---

### **Q1. Multiplication Table Generator**

#### ✅ Normal Function

```javascript
function printTable(num) {
  for (let i = 1; i <= 10; i++) {
    console.log(`${num} x ${i} = ${num * i}`);
  }
}
```

#### ✅ Arrow Function

```javascript
const printTable = (num) => {
  for (let i = 1; i <= 10; i++) {
    console.log(`${num} x ${i} = ${num * i}`);
  }
};
```

---

### **Q2. Count Digits in a Number**

#### ✅ Normal Function

```javascript
function countDigits(num) {
  let count = 0;
  while (num !== 0) {
    num = Math.floor(num / 10);
    count++;
  }
  return count;
}
```

#### ✅ Arrow Function

```javascript
const countDigits = (num) => {
  let count = 0;
  while (num !== 0) {
    num = Math.floor(num / 10);
    count++;
  }
  return count;
};
```

📌 **Note**: You might want to handle zero separately, as `countDigits(0)` would return 0 in this code. You could add:

```js
if (num === 0) return 1;
```

---

### **Q3. Reverse a String**

#### ✅ Normal Function

```javascript
function reverseString(str) {
  let reversed = '';
  for (let i = str.length - 1; i >= 0; i--) {
    reversed += str[i];
  }
  return reversed;
}
```

#### ✅ Arrow Function

```javascript
const reverseString = (str) => {
  let reversed = '';
  for (let i = str.length - 1; i >= 0; i--) {
    reversed += str[i];
  }
  return reversed;
};
```

---

### **Q4. Sum of Numbers Divisible by 3 or 5**

#### ✅ Normal Function

```javascript
function sumDivisible(limit) {
  let sum = 0;
  for (let i = 1; i <= limit; i++) {
    if (i % 3 === 0 || i % 5 === 0) {
      sum += i;
    }
  }
  return sum;
}
```

#### ✅ Arrow Function

```javascript
const sumDivisible = (limit) => {
  let sum = 0;
  for (let i = 1; i <= limit; i++) {
    if (i % 3 === 0 || i % 5 === 0) {
      sum += i;
    }
  }
  return sum;
};
```

---

## 📗 **Part B: Output Based Questions (Hoisting)**

---

### **Q1. Variable Hoisting**

```javascript
console.log(a);
var a = 10;
```

🧠 **Output:**

```
undefined
```

➡️ Because `var a` is hoisted but **initialized with `undefined`** before assignment.

---

### **Q2. Let & Const Hoisting**

```javascript
console.log(b);
let b = 20;
```

🧠 **Output:**

```
ReferenceError: Cannot access 'b' before initialization
```

➡️ `let` is hoisted but in the **Temporal Dead Zone (TDZ)** until its declaration is evaluated.

---

### **Q3. Function Declaration vs Function Expression**

```javascript
sayHello(); // ✅

function sayHello() {
  console.log("Hello from declaration!");
}

sayHi(); // ❌

var sayHi = function() {
  console.log("Hello from expression!");
};
```

🧠 **Output:**

```
Hello from declaration!
TypeError: sayHi is not a function
```

➡️ `sayHello()` is a function declaration (fully hoisted).
➡️ `sayHi` is a `var` (hoisted as `undefined`), so calling it before assignment causes a `TypeError`.

---

### **Q4. Arrow Function Hoisting**

```javascript
greet(); // ❌

const greet = () => {
  console.log("Hi there!");
};
```

🧠 **Output:**

```
ReferenceError: Cannot access 'greet' before initialization
```

➡️ `const` is hoisted but not initialized (TDZ). So you can’t call `greet()` before its definition.

---

### **Q5. Mixing var and let**

```javascript
console.log(x); // ✅
var x = 5;

console.log(y); // ❌
let y = 10;
```

🧠 **Output:**

```
undefined
ReferenceError: Cannot access 'y' before initialization
```

➡️ `x` is hoisted and initialized as `undefined` (var).
➡️ `y` is hoisted but not accessible before its declaration (TDZ - let).

---

## ✅ Summary

| Topic                | `var`       | `let` / `const` | Function Declaration | Function Expression / Arrow |
| -------------------- | ----------- | --------------- | -------------------- | --------------------------- |
| Hoisted              | Yes         | Yes (TDZ)       | Yes                  | Yes (as variable)           |
| Initialized on Hoist | `undefined` | ❌ (TDZ)         | Yes                  | `undefined`                 |
| Can be used before?  | Yes         | ❌               | Yes                  | ❌                           |

---

Let me know if you'd like this in a downloadable format (PDF or DOCX) or need help running these in a browser or Node.js.
