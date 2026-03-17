#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void f(vector<int> &temp, int sum, int index, vector<int> &v, vector<int> &arr) {
    if(index >= arr.size()) {
        v.push_back(sum);
        return;
    }
    temp.push_back(arr[index]);
    f(temp, sum + arr[index], index + 1, v, arr);
    temp.pop_back();
    f(temp, sum, index + 1, v, arr);
}

int main() {
    vector<int> arr;
    int n = 0;
    cout << "Enyer the number of elements in array: " << endl;
    cin >> n;
    cout << "Enter the elements of array: " << endl;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x; 
        arr.push_back(x);
    }
    vector<int> v;
    vector<int> temp;
    f(temp, 0, 0, v, arr);
    sort(v.begin(), v.end());
    for(int x : v) {
        cout << x << " ";
    }
    return 0;
}