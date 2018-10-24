//
// Created by Nick on 2018/10/24.
//

#include <vector>
#include <iostream>

using namespace std;

vector<int> min_max(vector<int> A) {
    int min = INT_MAX;
    int max = INT_MIN;
    for (int n : A) {
        if (n > max)
            max = n;
        if (n < min)
            min = n;
    }
    return vector<int>{min, max};
}

int bucket_no(int start, int end, int bucket, int n) {
    return ((double) (n - start)) / (end - start + 1) * bucket;
}

void bucket_sort(vector<int> &A) {
    vector<vector<int>> B(A.size(), vector<int>(0));
    for (int i = 0; i < A.size(); ++i) {
        B[A[i] / A.size()].push_back(A[i]);
    }
    for (int j = 0; j < B.size(); ++j) {
        insertion_sort(B[j]);
    }
    int n = 0;
    for (int i = 0; i < B.size(); ++i) {
        for (int j = 0; j < B[i].size(); ++j) {
            A[n++] = B[i][j];
        }
    }
}

void bucket_sort_custom(vector<int> &A, int bucket) {
    vector<int> m_m = min_max(A);
    int min = m_m[0];
    int max = m_m[1];

    vector<vector<int>> B(bucket, vector<int>(0));
    for (int i = 0; i < A.size(); ++i) {
        B[bucket_no(min, max, bucket, A[i])].push_back(A[i]);
    }
    for (int j = 0; j < B.size(); ++j) {
        insertion_sort(B[j]);
    }
    int n = 0;
    for (int i = 0; i < B.size(); ++i) {
        for (int j = 0; j < B[i].size(); ++j) {
            A[n++] = B[i][j];
        }
    }
}

int main() {
    vector<int> A = {78, 17, 39, 26, 72, 4, 21, 12, 23, 68};
    bucket_sort_custom(A, 5);
    for (int n : A) {
        cout << n << " ";
    }
}