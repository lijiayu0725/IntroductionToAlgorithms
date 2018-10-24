//
// Created by Nick on 2018/10/24.
//
#include <vector>
#include <iostream>
#include <map>

using namespace std;

void counting_sort(vector<int> &A, vector<int> &B, int k) {
    vector<int> C(k + 1);
    for (int i = 0; i < A.size(); ++i) {
        C[A[i]]++;
    }
    for (int j = 1; j <= k; ++j) {
        C[j] += C[j - 1];
    }
    for (int j = A.size() - 1; j >= 0; --j) {
        B[C[A[j]]--] = A[j];
    }

}

int main() {
    vector<int> A = {9, 8, 8, 0, 0, 07, 6, 6, 6, 5, 4, 3, 3, 2, 1, 2, 1};
    vector<int> B(A.size());
    counting_sort(A, B, 9);
    for (int i = 0; i < B.size(); ++i) {
        cout << B[i] << " ";
    }
}