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
#include <iostream>

int main() {
    // Declare a pointer and initialize it to null
    int* ptr = nullptr;

    // Check if the pointer is null before dereferencing it
    if (ptr == nullptr) {
        std::cout << "The pointer is null." << std::endl;
    } else {
        std::cout << "The pointer is not null." << std::endl;
    }

    // Uncommenting the following line will cause a runtime error (undefined behavior)
    // std::cout << *ptr << std::endl;  // Dereferencing a null pointer

    return 0;
}
