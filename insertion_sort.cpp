//
// Created by Nick on 2018/10/9.
//
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertion_sort(vector<int> &A) {
    for(int i = 1; i < A.size(); i++) {
        int key = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

void insertion_sort_custom(vector<int> &nums) {
    for(int i = 1; i < nums.size(); i++) {
        for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; --j) {
            swap(nums[j], nums[j + 1]);
        }
    }
}