// find minimum element in array

function minVal(n){
    let small_val = n[0]
    for (let i=0; i < n.length; i++){
        if (n[i] < small_val){
            small_val = n[i];
        }
    }
    return small_val;
}

let my_array = [7, 12, 9, 4, 11]
// console.log(minVal(my_array))



// ------------------------------------------
// Bubble Sort in array

function bubbleSort(arr){
    let len = arr.length;

    for (let i = 0; i < len-1; i++){
        for (let j = 0; j < len-i-1; j++){
            if(arr[j] > arr[j+1]){
                let temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

let my_array1 = [64, 34, 25, 12, 22, 11, 90, 5]
// console.log(my_array1)
// console.log(bubbleSort(my_array1))





//---------------------------------------------------------

/*

Bubble Sort Improvement
The Bubble Sort algorithm can be improved a little bit more.

Imagine that the array is almost sorted already, with the lowest numbers at the start, like this for example:

my_array = [7, 3, 9, 12, 11]
In this case, the array will be sorted after the first run, but the Bubble Sort algorithm will continue to run, without swapping elements, and that is not necessary.

If the algorithm goes through the array one time without swapping any values, the array must be finished sorted, and we can stop the algorithm, like this:

*/

function bubbleSort1(arr) {
    let len = arr.length;

    for (let i = 0; i < len - 1; i++) {
        let swapped = false
        for (let j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                let temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (!swapped){
            break;
        }
    }
    return arr;
}

let my_array2 = [7, 3, 9, 12, 11]
console.log(bubbleSort1(my_array2))