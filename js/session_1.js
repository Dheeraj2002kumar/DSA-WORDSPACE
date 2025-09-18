// let a = 10;
// let b = "abc";

// console.log("a + b is ", a+b)
// console.log("a - b is ", a-b)
// console.log("a * b is ", a*b)
// console.log("a / b is ", a/b)


// console.log("a + b typeof is ", typeof(a+b))
// console.log("a - b typeof is ", typeof(a-b))
// console.log("a * b typeof is ", typeof(a*b))
// console.log("a / b typeof is ", typeof(a/b))



// Parent
//   ↓ props
// Child
//   ↑ callbacks
// Parent



// // Greeting.js
// function Greeting({ name }) {
//   return <h1>Hello, {name}!</h1>;
// }

// // App.js
// function App() {
//   return (
//     <div>
//       <Greeting name="Sara" />
//       <Greeting name="John" />
//     </div>
//   );
// }







// import { useState } from 'react';

// function Counter() {
//   const [count, setCount] = useState(0);

//   const handleClick = () => {
//     setCount(count + 1);
//   };

//   return (
//     <div>
//       <p>You clicked {count} times</p>
//       <button onClick={handleClick}>
//         Click me
//       </button>
//     </div>
//   );
// }


let a = 10 + "20"
console.log(a);

console.log("5" * 2 + "1")

console.log("10" - "7" + 3);

console.log(null == undefined, null === undefined);

console.log([] + 1, [1] + 1);

let x;
console.log(typeof x, typeof y);



'use strict';
const user = { name: "Bicky", age: "29", active: "true", scores: ["10", "20", 30], meta: null };
const A = "10", B = 10, C = "42", D = 0, E = undefined, F = null, G = NaN;
const obj = { "key-1": 1, nested: { x: "2", y: 3 }, "weird prop": "ok" };


// B1 (4 marks). Strict match “42”. Create isFortyTwoString that is true only if a value is exactly the string "42" using C.
const isFortyTwoString = C === "42";

// B2 (5 marks). Force numeric addition. Create sumAB that equals 20 using A and B with explicit coercion (no string concatenation).
const sumAB = Number(A) + B;

// B3 (4 marks). String concatenation. Create concatAB that equals the string "1020" using A and B.
const concatAB = A + String(B);

// B4 (5 marks). Property access + numeric sum. Read obj["weird prop"] into weirdVal. Create nestedSum as numeric sum of obj.nested.x and obj.nested.y (result should be 5).
const weirdVal = obj["weird prop"];
const nestedSum = Number(obj.nested.x) + obj.nested.y;

// B5 (5 marks). Safe numbers & booleans. From user, create ageNum as a number, and activeBool as a boolean (non-empty string → true).
const ageNum = Number(user.age);
const activeBool = Boolean(user.active);

// B6 (5 marks). Prevent accidental concatenation (alt coercion). Create safeTotal that adds A and B to get 20 but without using Number(A). Use a different explicit coercion method.
const safeTotal = +A + B;

// B7 (4 marks). Equality snapshots. Create variables:
// p1Loose, p1Strict for 10 vs "10"
// p2Loose, p2Strict for null vs undefined. Log them in one line.
const p1Loose = 10 == "10";
const p1Strict = 10 === "10";
const p2Loose = null == undefined;
const p2Strict = null === undefined;
console.log(p1Loose, p1Strict, p2Loose, p2Strict);

console.log('DONE');







// Section A - Arrays

// 1. Remove Duplicates

function removeDuplicates(arr) {
  const result = [];
  for (const num of arr) {
    if (!result.includes(num)) {
      result.push(num);
    }
  }
  return result;
}

console.log(removeDuplicates([1, 2, 3, 2, 1, 4]))


// 2. Reverse an Array
function reverseArray(arr) {
  const reversed = [];

  for (let i = arr.length - 1; i >= 0; i--) {
    reversed.push(arr[i]);
  }
  return reversed;
}

console.log(reverseArray([10, 20, 30, 40]))



// 3. Find Second Largest Element 
function secondLargest(arr) {
  let max = -Infinity;
  let secondMax = -Infinity;

  for (const num of arr) {
    if (num > max) {
      secondMax = max;
      max = num;
    } else if (num > secondMax && num < max) {
      secondMax = num;
    }
  }
  return secondMax;
}

console.log(secondLargest([4, 1, 9, 2, 10, 9]))



// Section B - Objects (Frequency Mapping)

// 4. Character Frequency
function charFrequency(str) {
  const freq = {};

  for (const char of str) {
    freq[char] = (freq[char] || 0) + 1;
  }
  return freq;
}

console.log(charFrequency("programming"));



// 5. Word Frequency
function wordFrequency(sentence) {
  const words = sentnce.split(" ");
  const freq = {};

  for (const word of words) {
    freq[word] = (freq[word] || 0) + 1;
  }
  return freq;
}

console.log(wordFrequency("the cat and the dog and the rat"));


// 6. Most Frequent element in array
function mostFrequent(arr) {
  const freq = {};
  let maxCount = 0;
  let mostFreqElem = null;

  for (const num of arr) {
    freq[num] = (freq[num] || 0) + 1;

    if (freq[num] > maxCount) {
      maxCount = freq[num];
      mostFreqElem = num;
    }
  }
  return mostFreqElem;
}

console.log(mostFrequent([1, 2, 2, 3, 3, 3, 4]));


// Section C - Array of Objects(Advanced)

// 7. Group Employees by department
function groupByDept(employees) {
  const grouped = {};

  for (const emp of employees) {
    if (!grouped[emp.dept]) {
      grouped[emp.dept] = [];
    }
    grouped[emp.dept].push(emp.name);
  }
  return grouped;
}

console.log(groupByDept([
  { name: "Aman", dept: "IT" },
  { name: "Neha", dept: "HR" },
  { name: "Ravi", dept: "IT" },
]));


// 8. E-commerce Cart with Discounts
function calculateFinalBill(cart) {
  let total = 0;
  for (const item of cart) {
    total += item.price * item.qty;
  }

  if (total >= 1000) {
    total *= 0.9;
  }

  total *= 1.05;
  if (total < 500) {
    total += 50;
  }
  return Math.round(total);
}

console.log(calculateFinalBill([
  { name: "Shoes", Price: 500, qty: 2 },
  { name: "Bag", Price: 300, qty: 1 }
]));


// 9. Merge Duplicate Products
function mergeDuplicates(cart) {
  const merged = {};

  for (const item of cart) {
    if (merged[item.name]) {
      merged[item.name].qty += 1;
    } else {
      merged[item.name] = { ...item, qty: 1 };
    }
  }
  return Object.values(merged);
}

console.log(mergeDuplicates([
  { name: "Pen", price: 10 },
  { name: "Book", price: 50 },
  { name: "Pen", price: 10 }
]));



// 10. Keep Latest Login Record
function keepLatestLogins(logins) {
  const latest = {};

  for (const record of logins) {
    const id = record.id;
    if (!latest[id] || record.timestamp > latest[id].timestap) {
      latest[id] = record;
    }
  }
  return Object.values(latest);
}


console.log(keepLatestLogins([
  { id: 1, username: "Aman", timestamp: 100 },
  { id: 1, username: "Aman", timestamp: 200 },
  { id: 2, username: "Neha", timestamp: 150 }
]))
























