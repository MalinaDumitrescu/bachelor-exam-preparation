#include <iostream>
#include <vector>
using namespace std;
#include "searching_algorithms.hpp"

int sequentialSearch(vector<int>& array, int target, int length){
    for(int i = 0; i < length ; i++){
        if(array[i] == target){
            return i;
        }
    }
    return -1;
  
}

/* 
Complexity: O(n)
Best Case: O(1)
Average Case: O(n)
Worst Case: O(n) 
*/

int binarySearch(vector<int>& array, int target, int length){
    int left = 0;
    int right = length - 1;
    
    while(left <= right){
        int middle = left + (right - left)/2;
        if(array[middle] == target){
            return middle;
        }
        if(array[middle] < target){
            left = middle + 1;
        } else {
            right = middle - 1;
        }    
        
    }
    return -1;
}

/* 
Complexity: O(logn)
Best Case: O(1)
Average Case: O(logn)
Worst Case: O(logn) 
*/