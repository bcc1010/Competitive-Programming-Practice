#include <iostream>
#include <vector>
using std::vector;
using std::pair;

int findFirstTargetPos(const vector<int>& nums, int target) {
    // Binary search, moving left
    int left = 0;
    int right = (int)nums.size() - 1;
    int first_pos = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            first_pos = mid;
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return first_pos;
}

int findLastTargetPos(const vector<int>& nums, int target) {
    // Binary search, moving right
    int left = 0;
    int right = (int)nums.size() - 1;
    int last_pos = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            last_pos = mid;
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return last_pos;
}

pair<int, int> findFirstLastTargetPos(const vector<int>& nums, int target) {
    int first_pos = findFirstTargetPos(nums, target);
    if (first_pos == -1) return {-1, -1};      // Early exit - target not found
    int last_pos = findLastTargetPos(nums, target);
    return {first_pos, last_pos};
}

int main() {
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    std::cout << findFirstLastTargetPos(nums1, target1).first << '\n';
    std::cout << findFirstLastTargetPos(nums1, target1).second << '\n' << '\n';

    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    std::cout << findFirstLastTargetPos(nums2, target2).first << '\n';
    std::cout << findFirstLastTargetPos(nums2, target2).second << '\n' << '\n';

    vector<int> nums3 = {};
    int target3 = 0;
    std::cout << findFirstLastTargetPos(nums3, target3).first << '\n';
    std::cout << findFirstLastTargetPos(nums3, target3).second << '\n' << '\n';
}