#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        int index = 0;

        while(index < address.size()){
            if (address[index] == '.'){
                ans += "[.]";
            } else{
                ans += address[index];
            }
            index++;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string ip;

    cout << "Enter an IP address: ";
    cin >> ip;

    string defanged = solution.defangIPaddr(ip);

    cout << "Defanged IP address: " << defanged << endl;

    return 0;
}