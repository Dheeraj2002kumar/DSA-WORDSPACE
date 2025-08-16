// STL (Vector)

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    // create vector, declare
    vector<int>v;
    vector<int>v1(5, 1);

    // size and capacity
    // cout << "Size of v: " << v.size() << endl;
    // cout << "Capacity of v: " << v.capacity() << endl;
    
    v.push_back(2);
    v.push_back(3);
    v.push_back(10);
    // cout << "Size of v: " << v.size() << endl;
    // cout << "Capacity of v: " << v.capacity() << endl;

    // update value
    v[1] = 5;
    // cout << "Value of v: " << endl;

    // for (int i = 0; i <= v.size(); i++){
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    // cout << "Size of v1: " << v1.size() << endl;
    // cout << "Capacity of v1: " << v1.capacity() << endl;

    // v1.push_back(8);
    // cout << "Size of v1: " << v1.size() << endl;
    // cout << "Capacity of v1: " << v1.capacity() << endl;

    // vector<int>v2 = {1, 2, 3, 4, 5};
    // cout << "Size of v2: " << v2.size() << endl;
    // cout << "Capacity of v2: " << v2.capacity() << endl;


    // ---------------------------------------------------------
    
    // Delete value from vector
    // vector<int>vnew;
    // vnew.push_back(4);
    // vnew.push_back(5);
    // vnew.push_back(6);
    // vnew.push_back(7);
    // vnew.push_back(8);

    // cout << "Size of vnew: " << vnew.size() << endl;
    // cout << "Capacity of vnew: " << vnew.capacity() << endl;

    // // print the value
    // for(int i = 0; i < vnew.size(); i++){
    //     cout << vnew[i] << " ";
    // }
    // cout<< endl;

    // // delete value

    // vnew.pop_back();
    // cout << "Size of vnew: " << vnew.size() << endl;
    // cout << "Capacity of vnew: " << vnew.capacity() << endl;
    // // print the value
    // for (int i = 0; i < vnew.size(); i++){
    //     cout << vnew[i] << " ";
    // }
    // cout << endl;

    // // remove element from begin
    // vnew.erase(vnew.begin() + 1);
    // cout << "Size of vnew: " << vnew.size() << endl;
    // cout << "Capacity of vnew: " << vnew.capacity() << endl;

    // // print the value
    // for (int i = 0; i < vnew.size(); i++){
    //     cout << vnew[i] << " ";
    // }
    // cout << endl;

    // // insert element from begin + 1
    // vnew.insert(vnew.begin() + 1, 10); // vnew.begin() + 1 --> index value after element and 10 --> element that we want to insert
    
    // vnew.insert(vnew.begin() + 3, 55); // vnew.begin() + 3 --> index value after element and 55 --> element that we want to insert

    // // print the value
    // for (int i = 0; i < vnew.size(); i++){
    //     cout << vnew[i] << " ";
    // }
    // cout << endl;


    // // update the value at 2 index
    // vnew[1] = 100;
    // for (int i = 0; i < vnew.size(); i++){
    //     cout << vnew[i] << " ";
    // }
    // cout << endl;

    


    // // if we want to clear the element
    // vnew.clear();   // Remove all the element
    // cout << "Size of vnew: " << vnew.size() << endl;
    // cout << "Capacity of vnew: " << vnew.capacity() << endl;

 
    
    // ------------------------------------------------------------

    // print first and last element
    // vector<int>arr;
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(4);
    // arr.push_back(5);

    // // print first element
    // cout << "First element: " << arr.front() << endl;
    // cout << "First element: " << arr[0] << endl;  // this  second method

    // // print last element
    // cout << "Last element: " << arr.back() << endl;
    // cout << "Last element: " << arr[arr.size() - 1] << endl; // this second method
  

    // // copy value of vector<int>arr to vector<int>a
    // vector<int>a;
    // a = arr;
    // cout << "Size of a: " << a.size() << endl;
    // cout << "Capacity of a: " << a.capacity() << endl;

    // for (int i = 0; i < a.size(); i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;


    // // second method to print vector
    // for (auto i : arr){
    //     cout << i << " ";
    // }
    // cout << endl;




    // --------------------------------------------------------

    // sort the value of vactor arr
    // vector<int>ans;
    // ans.push_back(33);
    // ans.push_back(22);
    // ans.push_back(11);
    // ans.push_back(44);
    // ans.push_back(55);

    // // befor sorting the value
    // cout << "Before sorting: " << endl;
    // for (int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    
    // // after sorting the value
    // cout << "After sorting: " << endl;
    // sort(ans.begin(), ans.end()); // sort in accending order
    // for (auto i : ans){
    //     cout << i << " ";
    // }
    // cout << endl;


    // // sort in decresing order
    // sort(ans.begin(), ans.end(), greater<int>());

    // // second method to sort decresing order
    // // sort(ans.rbegin(), ans.rend());

    // cout << "After sorting in decresing order: " << endl;
    // for (int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
 


    // --------------------------------------------------------

    // Search in binary search
    vector<int>arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Size of arr: " << arr.size() << endl;
    cout << "Capacity of arr: " << arr.capacity() << endl;

    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // searching using binary_search function
    cout << binary_search(arr.begin(), arr.end(), 7) << endl;

    // find index value of particular element
    cout << find(arr.begin(), arr.end(), 5) - arr.begin() << endl;
    
    cout << lower_bound(arr.begin(), arr.end(), 7) - arr.begin() << endl;
    cout << upper_bound(arr.begin(), arr.end(), 7) - arr.begin() << endl;

    // find maximum and minimum value
    cout << "Maximum value: " << *max_element(arr.begin(), arr.end()) << endl;
    cout << "Minimum value: " << *min_element(arr.begin(), arr.end()) << endl;
    

    return 0;
}