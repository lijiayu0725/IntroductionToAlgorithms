//
// Created by Nick on 2018/10/20.
//
#include <vector>
#include <iostream>

using namespace std;

vector<int> find_max_crossing_subarray(vector<int> A, int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = INT_MIN;
    int max_right = INT_MIN;
    for (int i = mid; i >= low; --i) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int j = mid + 1; j <= high; ++j) {
        sum += A[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }
    vector<int> res = {max_left, max_right, left_sum + right_sum};
    return res;
}

vector<int> find_maximum_subarray(vector<int> A, int low, int high) {
    if (low == high) {
        vector<int> res = {low, high, A[low]};
        return res;
    }
    int mid = low + ((high - low) >> 1);
    vector<int> left_vec = find_maximum_subarray(A, low, mid);
    vector<int> right_vec = find_maximum_subarray(A, mid + 1, high);
    vector<int> cross_vec = find_max_crossing_subarray(A, low, mid, high);
    vector<int> res = left_vec[2] > right_vec[2] ? left_vec : right_vec;
    res = cross_vec[2] > res[2] ? cross_vec : res;
    return res;
}

int main() {
    vector<int> v = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    vector<int> res = find_maximum_subarray(v, 0, v.size() - 1);
    cout << "left = " << res[0] << " right = " << res[1] << " max = " << res[2] << endl;
}
