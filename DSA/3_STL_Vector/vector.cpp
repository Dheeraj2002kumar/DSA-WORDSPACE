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

    return 0;
}