#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#include "sorting_algorithms.hpp"

void merge(vector<int>& array, int left, int middle, int right){
    int i, j, k;
    int length1 = middle - left + 1;
    int length2 = right - middle;

    // temporary vectors
    vector<int> leftArray(length1), rightArray(length2);

    // Copy data to temporary vectors
    for(int i = 0; i < length1; i++){
        leftArray[i] = array[left + i];
    }
    for(int j = 0; j < length2 ; j++){
        rightArray[j] = array[middle + j + 1];
    }

    // merge temporary vector back into the original one

    i = 0;
    j = 0;
    k = left;

    while(i < length1 && j < length2){
        if(leftArray[i] <= rightArray[j]){
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }k++;
    } 

    // copy what is left out of the left array if needed 

    while(i < length1){
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // copy what is left out of the right array if needed 

    while (j < length2){
        array[k] = rightArray[j];
        j++;
        k++;        
    }
    
}

void mergeSort(vector<int>& array, int left, int right){
    if(left < right){
       int middle = left + (right - left)/2;

       mergeSort(array, left, middle);
       mergeSort(array, middle + 1, right);

       merge(array, left, middle, right);
    }

}

void selectionSort(vector<int> &array, int length){
    for(int i = 0; i < length - 1; i++){
        int minIndex = i;

        for(int j = i + 1; j < length; j++){
            if(array[j] < array[minIndex]){
                minIndex = j;
            }
        }
        swap(array[i],array[minIndex]);
    }
}

void bubbleSort(vector<int> &array, int length){
    bool swapped;
    for(int i = 0; i < length - 1; i++){
        swapped = false;
        for(int j = 0; j < length - i - 1; j++){
            if(array[j] > array[j + 1]){
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        // if no two elements were swapped -> break
        if(!swapped){
            break;
        }
    }
}