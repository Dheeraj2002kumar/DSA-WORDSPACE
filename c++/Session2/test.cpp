#include<iostream>
using namespace std;

int main(){
  int a[] = {1, 2, 3, 4, 5};
  int sum = 0;

  for(int i = 0; i < 5; i++){
    if(i % 2 == 0){
      sum += a[i];
    }
  }
  cout << "Sum of even indexed elements: " << sum << endl;
  return 0;
}