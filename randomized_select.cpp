//
// Created by Nick on 2018/10/28.
//
#include "quick_sort.cpp"

int randomized_select(vector<int> A, int p, int r, int i) {
    if (p == r) {
        return A[p];
    }
    int q = partition(A, p, r);
    int k = q - p + 1;
    if (k == i) {
        return A[q];
    }
    if (k > i) {
        return randomized_select(A, p, q - 1, i);
    } else {
        return randomized_select(A, q + 1, r, i - k);
    }
}

int main() {
    vector<int> A = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << randomized_select(A, 0, A.size() - 1, 5) << endl;
}