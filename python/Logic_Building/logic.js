/*

Given a number n, check whether it is even or odd. Return true for even and false for odd.

Examples: 

Input: 2 
Output: true


Input: 5
Output: false

*/

function isEven(n){
    if (n % 2 == 0){
        return "true"
    } 
    else{
        return "false"
    }
}

// console.log(isEven(2))
// console.log(isEven(5))




// +++++++++++++++++++++++++++++++++++++++++++++


/*

Given a number n, we need to print its table. 

Examples : 

Input:  5
Output: 
5 * 1 = 5
5 * 2 = 10
5 * 3 = 15
5 * 4 = 20
5 * 5 = 25
5 * 6 = 30
5 * 7 = 35
5 * 8 = 40
5 * 9 = 45
5 * 10 = 50

*/

function printTable(n){
    let obj = []
    for (let i = 1; i <= 10; i++){
        console.log(`${n} * ${i} = ${n*i}`)
    }
}
let n = 5
printTable(n)