//
// Created by Nick on 2018/10/22.
//
#include <vector>
#include <iostream>

using namespace std;

void max_heapify(vector<int> &A, int i, int size) {
    int l = i << 1;
    int r = (i << 1) + 1;
    int largest = 0;
    if (l < size && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r < size && A[r] > A[largest])
        largest = r;
    if (largest != i) {
        swap(A[i], A[largest]);
        max_heapify(A, largest, size);
    }
}

void build_max_heap(vector<int> &A) {
    for (int i = A.size() / 2; i >= 1; --i) {
        max_heapify(A, i, A.size());
    }
}

void heap_sort(vector<int> &A) {
    build_max_heap(A);
    for (int i = A.size() - 1; i >= 2; --i) {
        swap(A[1], A[i]);
        max_heapify(A, 1, i);
    }
}

int heap_maximum(vector<int> A) {
    return A[1];
}

int heap_extract_max(vector<int> &A) {
    int max = A[1];
    swap(A[1], A[A.size() - 1]);
    A.pop_back();
    max_heapify(A, 1, A.size());
    return max;
}

void heap_increase_key(vector<int> &A, int i, int key) {
    A[i] = key;
    while (i > 1 && A[i / 2] < A[i]) {
        swap(A[i], A[i / 2]);
        i /= 2;
    }
}

void max_heap_insert(vector<int> &A, int key) {
    A.push_back(INT_MIN);
    heap_increase_key(A, A.size() - 1, key);
}

int main() {
    vector<int> A = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    build_max_heap(A);
    cout << heap_extract_max(A) << endl;
    for (int n : A) {
        cout << n << " ";
    }
}