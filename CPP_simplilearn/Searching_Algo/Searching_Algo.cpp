// +++++++++++++++++++++ Linear Search +++++++++++++++++++++++++++

/*

Linear Search = Iterate through a collection one element at a time

runtime complexity: O(n)

Disadvantages: Slow for large data sets

Advantages: Fast for searches of small to medium data sets
            Does not need to sorted 
            Useful for data structures that do not have random access (Linked List)
*/


#include <iostream>
using namespace std;

// Fuction to perform Linear Search
int LinearSearch(int arr[], int n, int target){
    for (int i = 0; i < n; i++){
        if(arr[i] == target){
            return i;  // Return the index of the target element
        }
    }
    return -1;  // Return -1 if the target element is not found
}

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 30;

    int result = LinearSearch(arr, n, target);
    if (result != -1){
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}

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