#include <iostream>
#include <vector>
#include "merge_sort.cpp"
using namespace std;

int main() {
    vector<int> nums = {5,2,4,7,1,3,2,6};
    merge_sort_custom(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}