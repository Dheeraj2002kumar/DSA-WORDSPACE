#include <stdio.h>

int main() {
    int age;
    // int d;
    printf("Enter your age: ");
    scanf("%d", &age); // Reads an integer and stores it in 'age'
    printf("You are %zu years old.", sizeof(age));
    return 0;
}


