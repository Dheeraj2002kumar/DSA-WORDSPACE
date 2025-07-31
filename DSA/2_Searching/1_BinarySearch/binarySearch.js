function binarySearch(arr, target){
    let left = 0;
    let right = arr.length - 1;

    while(left <= right){
        const mid = Math.floor((left + right) / 2);

        if (arr[mid] === target){
            return mid; // target found at index mid
        } 
        else if (arr[mid] < target){
            left = mid + 1; // search in the right half
        } 
        else { 
            right = mid - 1;  // search in the left half
        }
    }

    return -1;
}

let arr = [4, 3, 2, 5, 6];
let target = 5;
console.log("Index value of the target: ", binarySearch(arr, target));