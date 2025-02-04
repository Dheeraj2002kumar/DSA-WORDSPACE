// +++++++++++++++++++++ Linear Search +++++++++++++++++++++++++++

/*

Linear Search = Iterate through a collection one element at a time

runtime complexity: O(n)

Disadvantages: Slow for large data sets

Advantages: Fast for searches of small to medium data sets
            Does not need to sorted 
            Useful for data structures that do not have random access (Linked List)
*/


// #include <iostream>
// using namespace std;

// // Fuction to perform Linear Search
// int LinearSearch(int arr[], int n, int target){
//     for (int i = 0; i < n; i++){
//         if(arr[i] == target){
//             return i;  // Return the index of the target element
//         }
//     }
//     return -1;  // Return -1 if the target element is not found
// }

// int main(){
//     int arr[] = {10, 20, 30, 40, 50};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int target = 30;

//     int result = LinearSearch(arr, n, target);
//     if (result != -1){
//         cout << "Element found at index " << result << endl;
//     } else {
//         cout << "Element not found" << endl;
//     }

//     return 0;
// }

// T.C -> O(n)
// S.C -> (1)

/*

Explanation:
Linear Search Function:

The linearSearch function takes an array, its size, and the target value as input.

It iterates through the array and compares each element with the target value.

If the target value is found, it returns the index of the target element.

If the target value is not found after checking all elements, it returns -1.

Main Function:

The main function initializes an array and specifies a target value to search for.

It calls the linearSearch function to find the target value.

It prints the result, indicating whether the target element was found and its index, or if it was not found.

Time Complexity:
The time complexity of Linear Search is O(n), where n is the number of elements in the array. This is because in the worst case, the algorithm needs to check all elements in the array.

Space Complexity:
The space complexity of Linear Search is O(1) because it only uses a constant amount of extra memory regardless of the size of the input array.

*/










// +++++++++++++++++++++ Binary Search +++++++++++++++++++++++

// --> The time complexity of binary search in the best case is O(1)
// --> In the worst case, the time complexity is O(log n).

// Binary search = Search algorithm that finds the position of a target value within a sorted array. 
//                 Half of the array is eliminated during each "step"


#include <iostream>
using namespace std;

// Function to perform Binary Search
int binarySearch(int arr[], int n, int target){
    int left = 0;
    int right = n - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is greater, ignore the left half
        if (arr[mid] < target){
            left = mid + 1;
        }
        // If the target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Return -1 if the target is not found
    return -1;
}

int main(){
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, n, target);
    if (result != -1){
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}




/*

Explanation:
Binary Search Function:

The binarySearch function takes an array, its size, and the target value as input.

It initializes two pointers, left and right, representing the search interval.

It calculates the middle index (mid) and compares the target value with the element at mid.

If the target value is found at mid, it returns the index.

If the target value is greater than the element at mid, it searches the right half by updating left.

If the target value is smaller than the element at mid, it searches the left half by updating right.

The process repeats until the target is found or the search interval is empty.

Main Function:

The main function initializes a sorted array and specifies a target value to search for.

It calls the binarySearch function to find the target value.

It prints the result, indicating whether the target element was found and its index, or if it was not found.

Time Complexity:
The time complexity of Binary Search is O(log n), where n is the number of elements in the array. This is because the search interval is divided in half during each step.

Space Complexity:
The space complexity of Binary Search is O(1) because it only uses a constant amount of extra memory regardless of the size of the input array.

*/