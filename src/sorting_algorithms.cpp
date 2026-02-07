#include <iostream>
#include <vector>
using namespace std;

#include "sorting_algorithms.hpp"

void merge(vector<int>& array, int left, int right, int middle){
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

       merge(array, left, right, middle);
    }

}