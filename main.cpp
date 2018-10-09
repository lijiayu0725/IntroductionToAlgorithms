#include <iostream>
#include <vector>
#include "insertion_sort.cpp"
using namespace std;

int main() {
    vector<int> nums = {9,8,7,6,5,4,3,2,1};
    insertion_sort_custom(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}