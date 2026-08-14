#include <iostream>
#include <vector>
using std::vector;

int minSubarrayGETarget(const vector<int>& nums, int target) {
    if (nums.empty()) return 0;
    int left = 0;
    int min_len = INT_MAX;
    int sum = 0;
    for (int right = 0; right < (int)nums.size(); right++) {
        sum += nums[right];
        while (sum >= target && left <= right) {
            min_len = std::min(min_len, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return min_len == INT_MAX ? 0 : min_len;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int tgt1 = 7;
    vector<int> nums2 = {1, 4, 4};
    int tgt2 = 4;
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1};
    int tgt3 = 11;

    std::cout << minSubarrayGETarget(nums1, tgt1) << '\n';
    std::cout << minSubarrayGETarget(nums2, tgt2) << '\n';
    std::cout << minSubarrayGETarget(nums3, tgt3) << '\n';
}