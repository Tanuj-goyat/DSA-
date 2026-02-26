/* This program is to print n numbers 

  input: 4
  output: 
  1
  2
  3
  4
*/

#include <iostream>
using namespace std;

void f(int i, int n) {
    if(i <= n) {
        cout << i <<endl;
        f(i+1, n);
    }else return;
}

int main(){
    int n;
    cout << "Enter the value of n";
    cin >> n;
    f(1, n);
    return 0;
}