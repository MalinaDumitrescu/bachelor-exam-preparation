#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b) {
    return a + b;
}

void swap(int a, int b) {
    cout << a << " " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}

void swap_reference(int &a, int &b) {
    cout << a << " " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }cout << endl;
}

void set_number_index(int arr[], int target, int size_arr) {
    if ( target >= 0 && target <= (size_arr - 1)) {
        arr[target] = 0;
    }
}

int main () {
    cout << sum(2,4) << endl;
    swap(2, 3);

    int x = 3;
    int y = 4;
    swap_reference(x, y);
    int arr[] = {1, 2, 4, 6, 7, 9};
    int size_arr =  sizeof(arr)/ sizeof(arr[0]);
    print_array(arr,size_arr);
    set_number_index(arr, 2,size_arr);
    print_array(arr,size_arr);
    return 0;
}