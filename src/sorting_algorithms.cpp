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

void selectionSort(vector<int> &array, int length)
{
    // The outer loop selects the position where
    // the next smallest element should be placed
    //
    // We run at most (length - 1) passes because:
    // - after each pass, one element is placed in its final position
    // - when only one element remains, it is already sorted
    for (int i = 0; i < length - 1; i++)
    {
        // Assume the smallest element is at position i
        int minIndex = i;

        // The inner loop searches for the smallest element
        // in the unsorted part of the array (to the right of i)
        //
        // Why j = i + 1 ?
        // - positions [0 .. i-1] are already sorted
        // - comparing with them would be useless
        //
        // Why j < length ?
        // - we must scan all remaining elements to be sure
        //   we find the global minimum of the unsorted part
        for (int j = i + 1; j < length; j++)
        {
            // If a smaller element is found,
            // update the index of the minimum
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }

        // Place the smallest element found
        // at position i by swapping
        //
        // After this swap, element at index i
        // is in its final, correct position
        swap(array[i], array[minIndex]);
    }
}


void bubbleSort(vector<int> &array, int length)
{
    // swapped tells us whether we made at least one swap in this pass
    bool swapped;

    // Outer loop = number of passes.
    // We run at most (length - 1) passes because:
    // - after each pass, one element (the largest remaining) is placed correctly at the end
    // - after (length - 1) passes, all elements must be in correct order
    for (int i = 0; i < length - 1; i++)
    {
        swapped = false; // assume already sorted at the start of this pass

        // Inner loop scans the "unsorted" part of the array.
        //
        // Why j < length - i - 1 ?
        // 1) "- i" because the last i elements are already fixed (sorted) after i passes,
        //    so there is no reason to compare/move them again.
        // 2) "- 1" because we compare array[j] with array[j + 1],
        //    so j must stop at the last valid index that still has a neighbor on the right.
        //
        // Example: length=5, i=0 => j < 4 (compare 0-1,1-2,2-3,3-4)
        //          length=5, i=1 => j < 3 (compare 0-1,1-2,2-3) last element already fixed
        for (int j = 0; j < length - i - 1; j++)
        {
            // Compare adjacent elements
            if (array[j] > array[j + 1])
            {
                // Swap if they are in the wrong order.
                // This pushes the larger element to the right,
                // so the largest element of this pass ends up at the end of the unsorted region.
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        // If we did not swap anything in this entire pass,
        // then the array is already sorted -> stop early
        if (!swapped)
        {
            break;
        }
    }
}


void insertionSort(vector<int>& array)
{
    // We start from the second element because a single element
    // (at index 0) is already considered sorted
    for (int i = 1; i < array.size(); i++)
    {
        // The element that must be inserted into the sorted part is placed into an aux space, so we can have space for sifting 
        int key = array[i];

        // j is used to traverse the sorted part of the array
        // from right to left
        int j = i - 1;

        // Move all elements that are greater than key
        // one position to the right
        // This creates space for inserting key
        while (j >= 0 && array[j] > key)
        {
            // Shift the current element to the right into the empty position 
            array[j + 1] = array[j];

            // Move one position to the left because we want to shift from right to left -> two cases -> 1. we hit -1 o we are out of the loop, we hit >= 0 so we have to continue 
            j = j - 1;
        }

        // j stopped at the last element smaller than key,
        // so key must be inserted at position j + 1
        array[j + 1] = key;
    }
}
