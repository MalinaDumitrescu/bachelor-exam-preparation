#include <iostream>
#include <vector>
using namespace std;
#include "searching_algorithms.hpp"
#include "sorting_algorithms.hpp"

int main(){
    vector<int> array = {1,2,3,4,5};
    int length = size(array);
    int target;
    cout << "target:"<< endl;
    cin >> target;
    
    int position_seq_search = sequentialSearch(array, target, length);
    int position_binary_search = binarySearch(array, target, length);
    
    cout <<"poitions seq search: " << position_seq_search << endl;
    cout <<"positions binary search: " << position_binary_search << endl;
   
     mergeSort(array, 0, length -1);
    for (auto i : array){
        cout << i << " ";
    } return 0;
}
