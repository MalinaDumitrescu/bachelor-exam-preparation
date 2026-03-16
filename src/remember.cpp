#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> array){
    int n = sizeof(array);
    bool swapped;
    for(int i = 0; i < n - 1; i++){
        swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(array[j] > array[j + 1]){
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void insertionSort(vector<int> array){
    int n = sizeof(array);
    for(int i = 1; i < n; i++){
        int key = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            int j = j - 1;
        }
        array[j + 1] = key;
    }
}

void selectionSort(vector<int> array){
    int n = sizeof(array);
    for(int i = 0; i < n- 1; i++){
        int min_idx = i;
        for(int j = i + 1; j < n; j++){
            if(array[j] < array[min_idx]){
                min_idx = j;
            }
        }
        swap(array[i], array[min_idx]);
    }
}