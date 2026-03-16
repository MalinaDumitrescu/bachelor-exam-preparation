// Given an array of positive integers arr[] of size n, the task is to find second largest distinct element in the array.

// Note: If the second largest element does not exist, return -1.

// Examples:

// Input: arr[] = [12, 35, 1, 10, 34, 1]
// Output: 34
// Explanation: The largest element of the array is 35 and the second largest element is 34.

// Input: arr[] = [10, 5, 10]
// Output: 5
// Explanation: The largest element of the array is 10 and the second largest element is 5.

// Input: arr[] = [10, 10, 10]
// Output: -1
// Explanation: The largest element of the array is 10 there is no second largest element.

// Option 1:

// [Naive Approach] Using Sorting
// The idea is to sort the array in non-decreasing order. Now, we know that the largest element will be at index n - 1. 
// So, starting from index (n - 2), traverse the remaining array in reverse order. 
// As soon as we encounter an element which is not equal to the largest element, return it as the second largest element in the array. 
// If all the elements are equal to the largest element, return -1.

// Time Complexity: O(n*log(n)), as sorting the array takes O(n*log(n)) time and traversing the array can take O(n) time in the worst case,
// so total time complexity = (n*log(n) + n) = O(n*log(n)).
// Auxiliary space: O(1), as no extra space is required.

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int secondLargest1(vector<int> arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for(int i = n - 2; i >= 0; i--){
        if(arr[i] != arr[i - 1]){    // we are checking for the second number of the arr to be different than the first, as asked
            return arr[i];
        }
    }
    return -1;


}
// Option 2:

// [Better Approach] Two Pass Search
// The approach is to traverse the array twice. In the first traversal, find the maximum element. 
// In the second traversal, find the maximum element ignoring the one we found in the first traversal.

// Time Complexity: O(2*n) = O(n), as we are traversing the array two times.
// Auxiliary space: O(1), as no extra space is required.

int secondLargest2(vector<int> &arr){
    int n = arr.size();
    int largest = -1, secondLargest = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    for(int i = 0; i < n; i++){
        if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

// Option 3:

// [Expected Approach] One Pass Search
// The idea is to keep track of the largest and second largest element while traversing the array. 
// Initialize largest and secondLargest with -1. Now, for any index i,

// If arr[i] > largest, update secondLargest with largest and largest with arr[i].
// Else If arr[i] < largest and arr[i] > secondLargest, update secondLargest with arr[i]. 

// Time Complexity: O(n), as we are traversing the array only once.
// Auxiliary space: O(1)

int secondLargest3(vector<int>& arr){
    int n = arr.size();
    int largest = -1, secondLargest = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];

        } else if(arr[i] < largest && arr[i] > secondLargest){
            secondLargest = arr[i];
        }
    } return secondLargest;
}




// Given an array of n integers, the task is to find the third largest element. All the elements in the array are distinct integers. 

// Examples : 

// Input: arr[] = {1, 14, 2, 16, 10, 20}
// Output: 14
// Explanation: Largest element is 20, second largest element is 16 and third largest element is 14

// Input: arr[] = {19, -10, 20, 14, 2, 16, 10}
// Output: 16
// Explanation: Largest element is 20, second largest element is 19 and third largest element is 16 

// Option 1:

// [Naive Approach] Using Sorting - O(n * log n) time and O(1) space
// The idea is to sort the array and return the third largest element in the array which will be present at (n-3)'th index.

int thirdLargest1(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i = n - 3; i >= 0; i--){
        if(arr[i] != arr[i - 2]){
            return arr[i];
        }
      
    } return -1;

}

// Option 2:

// [Expected Approach - 1] Using Three Loops - O(n) time and O(1) space
// The idea is to iterate the array twice and mark the maximum and second maximum element 
// and then excluding them both find the third maximum element, i.e., the maximum element excluding the maximum and second maximum.

// Step by step approach:

// First, iterate through the array and find maximum.
// Store this as first maximum along with its index.
// Now traverse the whole array finding the second max, excluding the maximum element.
// Finally traverse the array the third time and find the third largest element i.e., excluding the maximum and second maximum.

int thirdLargest2(vector<int> &arr){
    int n = arr.size();
    int largest = INT_MIN;

    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    int secodnLargest = INT_MIN;
    for(int i = 0; i < 0; i++){
        if(arr[i] > secodnLargest && arr[i] < largest){
            secodnLargest = arr[i];
        }
    }

    int thirdLargest = INT_MIN;
    for(int i = 0; i < 0; i++){
        if(arr[i > thirdLargest && arr[i] < secodnLargest]){
            thirdLargest = arr[i];
        }
    }
     
    return thirdLargest;
}

// Option 3:

// [Expected Approach - 2] Using Three variables - O(n) time and O(1) space
// The idea is to traverse the array from start to end and to keep track of the three largest elements up to that index (stored in variables). So after traversing the whole array, 
// the variables would have stored the indices (or value) of the three largest elements of the array.

// Step by step approach: 

// Create three variables, first, second, third, to store indices of three largest elements of the array. (Initially all of them are initialized to a minimum value).
// Move along the input array from start to the end.
// For every index check if the element is larger than first or not. Update the value of first, if the element is larger, and assign the value of first to second and second to third. So the largest element gets updated and the elements previously stored as largest becomes second largest, and the second largest element becomes third largest.
// Else if the element is larger than the second, then update the value of second, and the second largest element becomes third largest.
// If the previous two conditions fail, but the element is larger than the third, then update the third.

int thirdLargest3(vector<int>& arr){
    int n = arr.size();
    int largest = INT_MIN, secondLargest = INT_MIN, thirdLargest = INT_MIN;

    for(int i = 0; i < 0; i++){
        if(arr[i] > largest){
            thirdLargest = secondLargest;
            secondLargest = largest;
            largest = arr[i];
        } else if(arr[i] > secondLargest){
            thirdLargest = secondLargest;
            secondLargest = arr[i];
        } else if(arr[i] > thirdLargest){
            thirdLargest =  arr[i];
        }
    }
    return thirdLargest;
}

// Reverse an array arr[]. Reversing an array means rearranging the elements such that the first element becomes the last, the second element becomes second last and so on.

// Examples:

// Input: arr[] = [1, 4, 3, 2, 6, 5]  
// Output:  [5, 6, 2, 3, 4, 1]
// Explanation: The first element 1 moves to last position, the second element 4 moves to second-last and so on.

// Input: arr[] = [4, 5, 1, 2]
// Output: [2, 1, 5, 4]
// Explanation: The first element 4 moves to last position, the second element 5 moves to second last and so on.

// Option 1:

// [Naive Approach] Using a temporary array - O(n) Time and O(n) Space
// The idea is to use a temporary array to store the reverse of the array.

// Create a temporary array of same size as the original array. 
// Now, copy all elements from original array to the temporary array in reverse order.
// Finally, copy all the elements from temporary array back to the original array.

// Time Complexity: O(n), Copying elements to a new array is a linear operation.
// Auxiliary Space: O(n), as we are using an extra array to store the reversed array.

void reverseArray1(vector<int> &arr){
    int n = arr.size();

    vector<int> temp(n);

    for(int i = 0; i < n; i++){
        temp[i] = arr[n - i - 1];
    }

    for(int i = 0; i < n; i++){
        arr[i] = temp[i];
    }
}

// Option 2:

// [Expected Approach - 1] Using Two Pointers - O(n) Time and O(1) Space
// The idea is to maintain two pointers: left and right, such that left points at the beginning of the array and right points to the end of the array. 

// While left pointer is less than the right pointer, swap the elements at these two positions. After each swap, 
// increment the left pointer and decrement the right pointer to move towards the center of array. 
// This will swap all the elements in the first half with their corresponding element in the second half.

void reverseArray2(vector<int> &arr){
    int left = 0, right = arr.size() - 1;
    while(left < right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

}

// Option 3:

// [Expected Approach - 2] By Swapping Elements - O(n) Time and O(1) Space
// The idea is to iterate over the first half of the array and swap each element with its 
// corresponding element from the end. So, while iterating over the first half, any element 
// at index i is swapped with the element at index (n - i - 1).

// Time Complexity: O(n), the loop runs through half of the array, so it's linear with respect to the array size.
// Auxiliary Space: O(1), no extra space is required, therefore we are reversing the array in-place.

void reverseArray3(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n/2; i++){
        swap(arr[i],arr[n - i -1]);
    }
}

// Option 4:

// Using Inbuilt Methods - O(n) Time and O(1) Space
// The idea is to use inbuilt reverse methods available across different languages. 

// Time Complexity: O(n), the reverse method has linear time complexity.
// Auxiliary Space: O(1) Additional space is not used to store the reversed array, as the in-built array method swaps the values in-place.

void reverseArray4(vector<int> &arr){
    reverse(arr.begin(), arr.end());
}

// Reverse an Array in groups of given size
// Last Updated : 22 Jul, 2025
// Given an array arr[] and an integer k, find the array after reversing every subarray of consecutive k elements in place. If the last subarray has fewer than k elements, reverse it as it is. Modify the array in place, do not return anything.

// Examples: 

// Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8], k = 3
// Output: [3, 2, 1, 6, 5, 4, 8, 7]
// Explanation: Elements is reversed: [1, 2, 3] → [3, 2, 1], [4, 5, 6] → [6, 5, 4], and the last group [7, 8](size < 3) is reversed as [8, 7]. 

// Input: arr[] = [1, 2, 3, 4, 5], k = 3
// Output: [3, 2, 1, 5, 4]
// Explanation: First group consists of elements 1, 2, 3. Second group consists of 4, 5.

// Input: arr[] = [5, 6, 8, 9], k = 5
// Output: [9, 8, 6, 5]
// Explanation: Since k is greater than array size, the entire array is reversed.

// [Approach] Fixed-Size Group Reversal
// Idea is to consider every sub-array of size k starting from the beginning of the array and reverse it. We need to handle some special cases. 
// => If k is not a multiple of n where n is the size of the array, for the last group we will have less than k elements left, we need to reverse all remaining elements. 
// => If k = 1, the array should remain unchanged. If k >= n, we reverse all elements present in the array.

// To reverse a subarray, maintain two pointers: left and right. Now, swap the elements at left and right pointers and increment left by 1 and decrement right by 1. Repeat till left and right pointers don't cross each other. 

// Time Complexity: O(n), we go through the entire array just once, reversing elements in groups of size k. Since we don’t revisit any element, the total work done grows linearly with the size of the array. So, if the array has n elements, it takes roughly n steps.
// Auxiliary Space: O(1), the reversal is done directly within the original array using just a few extra variables.




int main(){
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << secondLargest1(arr);
    cout << secondLargest2(arr);
    cout << secondLargest3(arr);

    cout << thirdLargest1(arr);
    cout << thirdLargest2(arr);
    cout << thirdLargest3(arr);

    reverseArray1(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}