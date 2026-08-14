#include <iostream>
#include <vector>
using std::vector;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int slow = 0;
    for (int fast = 1; fast < (int)nums.size(); fast++) {
        if (nums[slow] != nums[fast]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    nums.resize(slow + 1);
    return slow + 1;
}

int main() {
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int dedup_len_1 = removeDuplicates(nums1);
    int dedup_len_2 = removeDuplicates(nums2);
    for (int num : nums1) {
        std::cout << num << '\n';
    }
    std::cout << "Dedup len 1: " << dedup_len_1 << '\n' << '\n';
    for (int num : nums2) {
        std::cout << num << '\n';
    }
    std::cout << "Dedup len 2: " << dedup_len_2 << '\n' << '\n';
}