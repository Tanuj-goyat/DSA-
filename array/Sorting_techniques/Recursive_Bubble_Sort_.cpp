#include <iostream>
using namespace std;

void sort(int arr[], int h) {
    if(h <= 1) return;
    for(int i = 0; i < h - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    sort(arr, h - 1);
}

int main() {

    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};

    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);

    for(int i : arr) {
        cout << i << " ";
    }

    return 0;
}