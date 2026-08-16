// Find the minimum difference between two elements
#include <vector>
#include <algorithm>
#include <climits>
using std::vector;

int minDiff(const vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int minDiff = INT_MAX;
    for (int i = 1; i < (int)nums.size(); i++) {
        minDiff = std::min(minDiff, nums[i] - nums[i - 1]);
    }
    return minDiff;
}