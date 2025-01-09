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