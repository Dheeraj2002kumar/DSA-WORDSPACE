// ++++++++++++++++ Pointers +++++++++++++++++++++++++++++++

/*

A Pointer is a variable pointing to the address of another variable. It is declared along with an asterisk symbol (*). The Syntgax to declare an pointer is as follows.
    datatype *var1

The Syntax to Assign address of a variable to a pointer is: 
    datatype var1, *var2;
    var2 = &var1

*/

// #include<bits/stdc++.h>
// using namespace std;

// main(){
//     int a = 5, *ptr;
//     ptr = &a;

//     cout << "a = " << a << endl;
//     cout << "a = " << *ptr << endl;
// }







/*

---------------- Types of Pointers ---------------------------
Pointer = 1. Null pointer
          2. void pointer
          3. wild pointer
          4. Dagling pointer


1. Null Pointer: If we assign a Null value to a pointer during its declaration, this pointer is called Null Pointer.

Syntax:
    Int *var = Null;


    Pointer ==> Null address


*/

// Null pointer 
// #include <iostream>

// int main() {
//     // Declare a pointer and initialize it to null
//     int* ptr = nullptr;

//     // Check if the pointer is null before dereferencing it
//     if (ptr == nullptr) {
//         std::cout << "The pointer is null." << std::endl;
//     } else {
//         std::cout << "The pointer is not null." << std::endl;
//     }

//     // Uncommenting the following line will cause a runtime error (undefined behavior)
//     // std::cout << *ptr << std::endl;  // Dereferencing a null pointer

//     return 0;
// }











/*

2. Void Pointer
    When a pointer is declared with a void keyword then this pointer is called void pointer. To print the value we need to typecaset this pointer

Syntax: 
    void *var;

    pointer ==> Any type of variable

*/

// #include <iostream>

// int main() {
//     int a = 10;
//     double b = 3.14;
    
//     // Declare a void pointer
//     void* ptr;

//     // Point the void pointer to an integer
//     ptr = &a;
//     std::cout << "Value of a (int): " << *(static_cast<int*>(ptr)) << std::endl;

//     // Point the void pointer to a double
//     ptr = &b;
//     std::cout << "Value of b (double): " << *(static_cast<double*>(ptr)) << std::endl;

//     return 0;
// }


/*

Explanation:
- A void pointer (void* ptr) is a pointer that can point to any data type, but you cannot directly dereference it.

- To dereference a void pointer, you need to cast it to the appropriate data type first, using static_cast<Type*>.

- In this example, ptr first points to an int (a) and then to a double (b).

*/










/*

3. Wild pointer
    A wild pointer is a pointer that is only declare but not assigned an address of any variable. 
    These pointers are very tricky, and they may cause segmentation errors. 

    Pointer != Variable


A wild pointer in C++ is a pointer that has been declared but not initialized, or a pointer that points to a random memory location. Dereferencing a wild pointer leads to undefined behavior and can result in crashes or unpredictable program behavior.

*/


// #include <iostream>

// int main() {
//     int* ptr;  // Wild pointer, uninitialized

//     // Dereferencing a wild pointer is undefined behavior
//     // Uncommenting the following line will cause unpredictable behavior
//     // std::cout << *ptr << std::endl;  // Dereferencing wild pointer

//     std::cout << "Wild pointer may point to garbage memory." << std::endl;
//     std::cout << *ptr << std::endl;

//     int* ptr1 = nullptr;  // Safe initialization
//     std::cout << *ptr1 << std::endl;
    
//     return 0;
// }



/*

Explanation:
    
    - The pointer ptr is declared but not initialized, which makes it a wild pointer.
    
    - Dereferencing ptr without initializing it can lead to unpredictable behavior because it might point to an arbitrary memory location.
    
    - If you try to dereference a wild pointer (e.g., *ptr), your program will likely crash or produce garbage data.

To avoid wild pointers, always initialize pointers either to nullptr (or NULL in older C++) or to a valid memory location before dereferencing them. Here's how you might initialize it to nullptr:

*/












/*

4. Dangling Pointer:
    - Let's suppose there is a pointer p pointing at a variable at memory 1004. This pointer will point at a deleted variable if we deallocate this memory, and this pointer p is called dangling pointer.

    - We deallocate memory using a free() function. 

    Pointer ==> variable (deallocate [delete]) ==> Free Space


A dangling pointer in C++ is a pointer that continues to reference a memory location after the object it points to has been deleted or gone out of scope. Dereferencing a dangling pointer leads to undefined behavior and can cause crashes or unpredictable behavior.

*/

// #include <iostream>

// int main() {
//     // Dynamically allocate memory for an integer
//     int* ptr = new int(42);

//     // Print the value pointed to by ptr
//     std::cout << "Value: " << *ptr << std::endl;

//     // Deallocate the memory
//     delete ptr;

//     // Now, ptr is a dangling pointer
//     // Dereferencing a dangling pointer is undefined behavior
//     // Uncommenting the following line may lead to a crash or unpredictable results
//     // std::cout << "Value after delete: " << *ptr << std::endl;

//     // Set the pointer to nullptr to avoid the dangling pointer
//     ptr = nullptr;

//     return 0;
// }



/*

Explanation:


    - Dynamically allocate memory: We allocate memory for an integer using new and assign the pointer ptr to it.

    - Deallocate memory: The delete operator frees the memory, but ptr still holds the address of the now-deleted memory.

    - Dangling pointer: After delete ptr;, ptr becomes a dangling pointer, meaning it points to a memory location that has been freed.

    - Dereferencing a dangling pointer: Dereferencing a dangling pointer (i.e., trying to access the memory it points to after deletion) leads to undefined behavior and can crash the program or give garbage data.

    - Avoid dangling pointer: The best way to avoid dangling pointers is to set the pointer to nullptr after deleting the memory (ptr = nullptr;), which ensures that it doesn’t point to an invalid memory location.

The output of the above program will correctly print Value: 42, and then it will end. If you try to dereference ptr after delete ptr;, the program will exhibit undefined behavior.
*/

// #include <iostream>
// using namespace std;

// int main() {
//     int* ptr = (int *)malloc(sizeof(int));  // Dynamically allocate memory
//     if (ptr == nullptr) {  // Always check if malloc was successful
//         cout << "Memory allocation failed!" << endl;
//         return 1;
//     }

//     *ptr = 5;  // Assign value to the allocated memory

//     cout << *ptr << endl;  // Output the value stored in dynamically allocated memory

//     free(ptr);  // Now it's safe to free the dynamically allocated memory

//     // ptr is now a dangling pointer. It's best to set it to nullptr
//     ptr = nullptr;

//     return 0;
// }











/*
--------------- Use-Cases of pointer --------------------

1. Pointer Arithmetic
2. Pointer to pointer
3. Array of pointers
4. Call by Vallue
5. Call by Reference



1. Pointer Arithmetic
    We can do different types of arithmetic operations on pointers: 
    Increment (++)
    Decrement (--)
    Integers can be added to pointers (+ or +=)
    Integers can be subtracted from pointers (- or -=)

Note: Pointer Arithmetic is of no use if not used on arrays


Increment(++):
    We can use this operator to jump from one index to the next index in an array Syntax: 
        ptr++;

        arr[0] ==> arr[1] ==> arr[2]
        ptr++       ptr++       ptr++
*/


// #include<iostream>
// using namespace std;

// main(){
//     int arr[3] = {2, 3, 5};
//     int *tr;
//     tr = &arr[0];

//     for (int i = 0; i < 3; i++){
//         cout << *tr << endl;
//         tr++;
//     }
//     return 0;
// }





/*

Decrement (--):
    We can use this operator to jump from one index to the previous index in an array.
    Syntax: 
        ptr--;

        arr[2] ==> arr[1] ==> arr[0]
        ptr--       ptr--       ptr--

*/

// #include <iostream>
// using namespace std;

// main(){
//     int arr[3] = {2, 3, 5};
//     int *ptr;
//     ptr = &arr[2];

//     for (int i = 0; i < 3; i++){
//         cout << *ptr << endl;
//         ptr--;
//     }
//     return 0;
// }





/*

Integers added to a pointer
    We can this operator to jump from one index to the next index in an array. 
    Syntax:
        ptr += i;  // where 'i' is an integer

        arr[0] ==> arr[2] ==> arr[4]
        ptr += 2    ptr += 2    ptr += 2

*/

// #include <iostream>
// using namespace std;

// int main() {
//     int arr[] = {1, 2, 3, 4, 5};  // Static array
//     int length = sizeof(arr) / sizeof(arr[0]);  // Calculate the number of elements

//     int* ptr = arr;  // Pointer pointing to the start of the array

//     int numberToAdd = 10;  // The number to add to each array element

//     // Add numberToAdd to each array element using the pointer
//     for (int i = 0; i < length; ++i) {
//         *ptr += numberToAdd;  // Dereference the pointer and add the number
//         ptr++;  // Move to the next element in the array
//     }

//     // Output the modified array
//     cout << "Modified array: ";
//     for (int i = 0; i < length; ++i) {
//         cout << arr[i] << " ";  // Print each element
//     }
//     cout << endl;

//     return 0;
// }







/*

++++++++++++ Pointer to Pointer ++++++++++++++++++++++

In C++, a pointer to a pointer is a concept where a pointer holds the address of another pointer. Essentially, it's a pointer that points to another pointer, which in turn points to a variable. This is typically used when working with dynamic memory or in scenarios where you want to manipulate the address of a pointer itself.


Syntax

type **pointer_name;

Here, type is the data type of the variable being pointed to, and pointer_name is the name of the pointer to pointer.

*/ 

// #include <iostream>
// using namespace std;

// int main(){
//     int value = 10;            // a normal integer variable
//     int *ptr1 = &value;        // ptr1 is a pointer to the integer value
//     int **ptr2 = &ptr1;        // ptr2 is a pointer to ptr1, which is pointer to value

//     cout << "Value: " << value << endl;
//     cout << "ptr1 points to: " << *ptr1 << endl;  // Dereferencing ptr1 gives the value
//     cout << "ptr2 points to: " << **ptr2 << endl; // Dereferencing ptr2 twice gives the value 

//     return 0;
// }


/*

------------- output ------------------
PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\CPP_simplilearn\Pointer> ./pointer
Value: 10
ptr1 points to: 10
ptr2 points to: 10
PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\CPP_simplilearn\Pointer>

*/ 

/*

Explanation:
value is an integer variable.
ptr1 is a pointer to the value variable (i.e., it stores the address of value).
ptr2 is a pointer to ptr1 (i.e., it stores the address of ptr1).
When you dereference ptr2 twice (**ptr2), you get the value of value.

Why Use Pointer to Pointer?
Dynamic memory management: When dealing with multi-dimensional arrays, you often use pointers to pointers.
Passing pointers by reference: If you want to modify the address stored in a pointer within a function, you use a pointer to a pointer.

*/