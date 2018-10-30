//
// Created by Nick on 2018/10/23.
//
#include <vector>
#include <iostream>

using namespace std;

//i i及i左边为小于主元A[r]的元素
//i + 1到r - 1最终为大雨主元的元素
//最后调换主元和A[i + 1] 返回i + 1

int partition(vector<int> &A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (A[j] <= x) {
            i += 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int randomized_partition(vector<int> &A, int p, int r) {
    long i = random() % (r - p + 1) + p;
    swap(A[r], A[i]);
    return partition(A, p, r);
}

void quick_sort(vector<int> &A, int p, int r) {
    if (p < r) {
        int q = randomized_partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}