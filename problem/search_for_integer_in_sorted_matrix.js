/*

Problem Description
Given a sorted matrix, come up with an efficient way to search for a value in the matrix. Each row in the matrix is sorted in ascending order from left to right. Each column in the matrix is sorted in ascending order from top to bottom.

Input format
The first line contains two space-separated integers N and M denoting the number of rows and columns respectively.

Next N lines contain M space-separated integers denoting the elements of the matrix A.

Next line contains the number of queries, Q

Next Q lines follow, each line contains the target element K which needs to be searched.

Output format
Print True if the target element is present in the matrix else print False.

Constraints
0 <= N, M <= 10^3

0 <= A(i,j) <= 10^9

0 <= Q <= 10^5

0 <= K <= 10^9

Sample Input 1

5 5

1 4 7 11 15

2 5 8 12 19

3 6 9 16 22

10 13 14 17 24

18 21 23 26 30

1

3

Sample Output 1
true

Explanation 1
The number 3 is present in the matrix.

Sample Input 2
5 5

1 4 7 11 15

2 5 8 12 19

3 6 9 16 22

10 13 14 17 24

18 21 23 26 30

3

5

20

30

Sample Output 2
true

false

true

Explanation 2
The number 20 is not present in the matrix. 5 and 30 are present in the matrix.



*/ 

function searchA2DMatrix(matrix, target){
    if (matrix.length === 0 || matrix[0].length === 0) return false;

    let row = 0;
    let col = matrix[0].length-1;

    while (row < matrix.length && col >= 0){
        if (matrix[row][col] === target){
            return true;
        } else if (matrix[row][col] < target){
            row++;  // Mave down
        } else {
            col--;  // move left
        }
    }

    return false;
}

// Reading input and processing multiple queries
function processQueries(matrix, queries){
    const result = [];
    for (let i = 0; i < queries.length; i++){
        result.push(searchA2DMatrix(matrix, queries[i]));
    }
    return result;
}

const N = 5, M = 5;
const matrix = [
    [1, 4, 7, 11, 15],
    [2, 5, 8, 12, 19],
    [3, 6, 9, 16, 22],
    [10, 13, 14, 17, 24],
    [18, 21, 23, 26, 30]
];

const queries = [3, 5, 20, 30];

const result = processQueries(matrix, queries);
result.forEach(result => console.log(result ? 'true' : 'false'));