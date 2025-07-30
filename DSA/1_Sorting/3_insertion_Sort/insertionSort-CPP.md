Here's a simple and clear **Insertion Sort implementation in C++**, along with an example that demonstrates how to use it:

---

### 🧠 **C++ Code: Insertion Sort**

```cpp
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {9, 5, 1, 4, 3};

    std::cout << "Original array:\n";
    printArray(arr);

    insertionSort(arr);

    std::cout << "Sorted array:\n";
    printArray(arr);

    return 0;
}
```

---

### 🧾 Output:

```
Original array:
9 5 1 4 3 
Sorted array:
1 3 4 5 9 
```

---

### 📌 Notes:

* This version uses a `std::vector<int>` for flexibility, but you can also use plain arrays (`int arr[]`) if needed.
* Time complexity is **O(n²)** in the worst case, but it's **O(n)** for nearly sorted input.

Would you like a version that sorts in **descending order**, or sorts **objects/structs** by a key?


Great! Let's go step by step. Below are **three variations** of **Insertion Sort in C++**:

---

### ✅ 1. **Descending Order (integers)**

```cpp
void insertionSortDescending(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements less than key
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
```

Use it like this:

```cpp
std::vector<int> arr = {3, 7, 2, 9, 1};
insertionSortDescending(arr);
```

---

### ✅ 2. **Sorting an Array of Structs by Key**

Suppose you have a `Student` struct, and you want to sort by `age`:

```cpp
#include <iostream>
#include <vector>

struct Student {
    std::string name;
    int age;
};

void insertionSortByAge(std::vector<Student>& students) {
    for (int i = 1; i < students.size(); ++i) {
        Student key = students[i];
        int j = i - 1;

        while (j >= 0 && students[j].age > key.age) {
            students[j + 1] = students[j];
            j--;
        }

        students[j + 1] = key;
    }
}

void printStudents(const std::vector<Student>& students) {
    for (const auto& s : students) {
        std::cout << s.name << " (" << s.age << ")\n";
    }
}

int main() {
    std::vector<Student> students = {
        {"Alice", 22},
        {"Bob", 19},
        {"Charlie", 21}
    };

    std::cout << "Before sorting:\n";
    printStudents(students);

    insertionSortByAge(students);

    std::cout << "\nAfter sorting by age:\n";
    printStudents(students);

    return 0;
}
```

---

### ✅ 3. **Sorting in Descending Order by Struct Field (e.g., age)**

Just reverse the comparison:

```cpp
while (j >= 0 && students[j].age < key.age)
```

---

Would you like one that sorts by **multiple fields** (e.g., by `age` then by `name`), or would you like it rewritten using **C-style arrays** instead of `std::vector`?
