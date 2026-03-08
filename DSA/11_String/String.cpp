#include <iostream>
using namespace std;

void swapString(string s){
    int start = 0, end = s.size()-1;

    while(start < end){
        swap(s[start], s[end]);
        start++, end--;
    }
    cout << s << endl;
}

int sizeString(string s){
    int size = 0;

    while(s[size] != '\0'){
        size++;
    }

    return size;
}

void isPalindrom(string s){
    int start = 0, end = s.size() - 1;

    while (start < end)     
    {
        if (s[start] != s[end]){
            cout << "Not a Palindrome";
            return;
        }

        start++;
        end--;
    }

    cout << "It is a Palindrome: " << s << endl;
    
}

int main(){
    string s1 = "rohit";
    swapString(s1);

    cout << sizeString(s1) << endl;

    string s2 = "madam";
    isPalindrom(s2);

    return 0;
}



// ------------------------------------

// #include <iostream>
// using namespace std;

// int main(){

//     // escap character
//     string s1 = "Dheeraj is a good backend \"developer\".";
//     cout << s1 << endl;

//     return 0;
// }



// -------------------- String method --------------------
// #include <iostream>
// using namespace std;

// int main(){

//     // string s;
//     // getline(cin, s); // getline can also read space
//     // cout << s << endl;
//     // cout << s.size();

//     string s1 = "rohit", s2 = "mohit";
    
//     // concat the string s1 and s2
//     string s3 = s1 + s2;
//     cout << s3 << endl;

//     // also apend the string in s1 or s2
//     s1.push_back('k');
//     cout << s1 << endl;

//     // also pop_back() method use, last character will be remove
//     s1.pop_back();
//     cout << s1 << endl;

//     // also concat with + operator
//     s1 = s1 + " kumar";
//     cout << s1 << endl;

//     return 0;
// }


// -------------------------------
// #include <iostream>
// using namespace std;

// int main(){

//     string s;
//     cin >> s;
//     cout << s;

//     return 0;
// }


// ----------------------------------------

// #include <iostream>
// using namespace std;

// int main(){

//     char arr[5];
//     cin >> arr;
//     arr[2] = '\0';
//     cout << arr;

//     return 0;
// }





// ---------------------------------------

// #include<iostream>
// using namespace std;

// int main(){
//     // char arr[] = {'a', 'p', 'p', 'l', 'e'};

//     // // cout << arr;
//     // for (int i = 0; i < 5; i++){
//     //     cout << arr[i] << endl;
//     // }
// }