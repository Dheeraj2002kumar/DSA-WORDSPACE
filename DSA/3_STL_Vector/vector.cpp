// STL (Vector)

#include<iostream>
#include<vector>
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

    
    // Delete value from vector
    vector<int>vnew;
    vnew.push_back(4);
    vnew.push_back(5);
    vnew.push_back(6);
    vnew.push_back(7);
    vnew.push_back(8);

    cout << "Size of vnew: " << vnew.size() << endl;
    cout << "Capacity of vnew: " << vnew.capacity() << endl;

    // print the value
    for(int i = 0; i < vnew.size(); i++){
        cout << vnew[i] << " ";
    }
    cout<< endl;

    // delete value

    vnew.pop_back();
    cout << "Size of vnew: " << vnew.size() << endl;
    cout << "Capacity of vnew: " << vnew.capacity() << endl;
    // print the value
    for (int i = 0; i < vnew.size(); i++){
        cout << vnew[i] << " ";
    }
    cout << endl;

    // remove element from begin
    vnew.erase(vnew.begin() + 1);
    cout << "Size of vnew: " << vnew.size() << endl;
    cout << "Capacity of vnew: " << vnew.capacity() << endl;

    // print the value
    for (int i = 0; i < vnew.size(); i++){
        cout << vnew[i] << " ";
    }
    cout << endl;

    // insert element from begin + 1
    vnew.insert(vnew.begin() + 1, 10); // vnew.begin() + 1 --> index value after element and 10 --> element that we want to insert
    
    vnew.insert(vnew.begin() + 3, 55); // vnew.begin() + 3 --> index value after element and 55 --> element that we want to insert

    // print the value
    for (int i = 0; i < vnew.size(); i++){
        cout << vnew[i] << " ";
    }
    cout << endl;


    // update the value at 2 index
    vnew[1] = 100;
    for (int i = 0; i < vnew.size(); i++){
        cout << vnew[i] << " ";
    }
    cout << endl;





    return 0;
}