Absolutely! Here's a **Bubble Sort implementation in C++**, with versions for:

1. **Ascending order**
2. **Descending order**
3. **Step-by-step output**

---

### ✅ 1. Bubble Sort in Ascending Order (C++)

```cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        // If no two elements were swapped, array is sorted
        if (!swapped)
            break;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "Sorted array in ascending order:\n";
    printArray(arr, n);

    return 0;
}
```

---

### 🔽 2. Bubble Sort in Descending Order (C++)

Just change the comparison operator:

```cpp
if (arr[j] < arr[j + 1]) {
    // Swap for descending order
}
```

---

### 👣 3. Bubble Sort with Step-by-Step Output

```cpp
#include <iostream>
using namespace std;

void printPass(int arr[], int n, int pass) {
    cout << "Pass " << pass << ": ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSortSteps(int arr[], int n) {
    bool swapped;
    int pass = 1;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        printPass(arr, n, pass++);
        if (!swapped)
            break;
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortSteps(arr, n);

    return 0;
}
```

---

Let me know if you want to sort **strings**, **custom objects**, or want to include **timing** (e.g., using `chrono`).

Perfect — here’s how to extend **Bubble Sort in C++** for:

---

## 🔤 Sorting Strings with Bubble Sort

This will sort strings in **lexicographical (dictionary) order**.

### ✅ Example: Sorting a vector of strings

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void bubbleSortStrings(vector<string>& arr) {
    bool swapped;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void printStrings(const vector<string>& arr) {
    for (const string& s : arr)
        cout << s << " ";
    cout << endl;
}

int main() {
    vector<string> names = {"Zara", "Anna", "John", "Mike"};

    bubbleSortStrings(names);

    cout << "Sorted strings:\n";
    printStrings(names);

    return 0;
}
```

---

## 👤 Sorting Objects by a Field (e.g., age)

### 🧍 Example: Sort people by age (ascending)

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Person {
    string name;
    int age;
};

void bubbleSortByAge(vector<Person>& people) {
    bool swapped;
    int n = people.size();

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (people[j].age > people[j + 1].age) {
                swap(people[j], people[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void printPeople(const vector<Person>& people) {
    for (const auto& p : people)
        cout << p.name << " (" << p.age << ")\n";
}

int main() {
    vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"Diana", 28}
    };

    bubbleSortByAge(people);

    cout << "Sorted people by age:\n";
    printPeople(people);

    return 0;
}
```

---

## ⏱️ Timing the Sort with `chrono`

You can measure how long the sort takes:

```cpp
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    bool swapped;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

int main() {
    vector<int> arr = {9, 4, 6, 3, 7, 2};

    auto start = high_resolution_clock::now();

    bubbleSort(arr);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Sorted array:\n";
    for (int num : arr)
        cout << num << " ";

    cout << "\nTime taken: " << duration.count() << " microseconds\n";

    return 0;
}
```

---

Let me know if you want:

* Descending order for strings or objects
* Bubble sort using C-style arrays
* GUI visualization (e.g., using SFML or Qt)
* Comparison with other sorting algorithms (like `std::sort`)

Ready to help!
