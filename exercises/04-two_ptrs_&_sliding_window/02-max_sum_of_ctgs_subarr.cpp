#include <iostream>
#include <vector>
#include <numeric>
using std::vector;

// Recognition trigger: fixed-size sliding window

int maxCtgsSubarraySum(const vector<int>& nums, int k) {
    int left = 0;
    int max_sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
    int curr_sum = max_sum;
    for (int right = k; right < (int)nums.size(); right++) {
        curr_sum -= nums[right - k];
        curr_sum += nums[right];
        max_sum = std::max(curr_sum, max_sum);
    }
    return max_sum;
}

int main() {
    vector<int> arr1 = {2, 1, 5, 1, 3, 2};
    int k1 = 3;

    vector<int> arr2 = {2, 3, 4, 1, 5};
    int k2 = 2;

    vector<int> arr3 = {1};
    int k3 = 1;

    std::cout << maxCtgsSubarraySum(arr1, k1) << '\n';
    std::cout << maxCtgsSubarraySum(arr2, k2) << '\n';
    std::cout << maxCtgsSubarraySum(arr3, k3) << '\n';
}