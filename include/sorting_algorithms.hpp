#pragma once
#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& array, int left, int right);
void merge(vector<int>& array, int left, int middle, int right);
void selectionSort(vector<int> &array, int length);
void bubbleSort(vector<int> &array, int length);
