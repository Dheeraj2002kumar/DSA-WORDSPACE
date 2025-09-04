
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
