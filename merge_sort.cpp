//
// Created by Nick on 2018/10/12.
//

#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int> &nums, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> L, R;
    for (int i = 0; i < n1; ++i) {
        L.push_back(nums[p + i]);
    }
    for (int j = 0; j < n2; ++j) {
        R.push_back(nums[q + 1 + j]);
    }
    L.push_back(1e9);
    R.push_back(1e9);
    int k = p, i = 0, j = 0;
    while(k <= r) {
        if (L[i] < R[j]) {
            nums[k++] = L[i++];
        } else {
            nums[k++] = R[j++];
        }
    }
}

void merge_sort(vector<int> &nums, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(nums, p, q);
        merge_sort(nums, q + 1, r);
        merge(nums, p, q, r);
    }
}

void merge_sort(vector<int> &nums) {
    merge_sort(nums, 0, nums.size() - 1);
}

void merge_custom(vector<int> &nums, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> temp;
    int i = 0, j = 0;
    while(i < n1 && j < n2) {
        if (nums[p + i] < nums[q + 1 + j]) {
            temp.push_back(nums[p + i]);
            i++;
        } else {
            temp.push_back(nums[q + 1 + j]);
            j++;
        }
    }
    while(i < n1) {
        temp.push_back(nums[p + i]);
        i++;
    }
    while(j < n2) {
        temp.push_back(nums[q + 1 + j]);
        j++;
    }
    for (int k = 0; k < r - p + 1; ++k) {
        nums[p + k] = temp[k];
    }

}

void merge_sort_custom(vector<int> &nums, int p, int r) {
    if (p < r) {
        int q = (p + r) >> 1;
        merge_sort_custom(nums, p, q);
        merge_sort_custom(nums, q + 1, r);
        merge_custom(nums, p, q, r);
    }
}

void merge_sort_custom(vector<int> &nums) {
    merge_sort_custom(nums, 0, nums.size() - 1);
}