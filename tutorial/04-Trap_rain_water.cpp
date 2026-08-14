#include <vector>
using std::vector;

// Given an array where each element represents the height of a bar, compute
// how much water can be trapped between the bars after rain.

// The key observation is that the water level at any position i is determined
// by the minimum height to its left and the maximum height to its right.
//      water_at_i = min(maxLeft, maxRight) - height[i]

// Using the two pointer approach:
int count_trapped_water(const vector<int>& height) {
    int left = 0;
    int right = (int)height.size() - 1;
    int maxLeft = 0, maxRight = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            // The limiting factor is the left side
            if (height[left] >= maxLeft) {
                maxLeft = height[left];             // New max on left, no water
            } else {
                water += maxLeft - height[left];    // Water trapped on left
            }
            left++;
        } else {
            // The limiting factor is the right side
            if (height[right] >= maxRight) {
                maxRight = height[right];           // New max on right, no water
            } else {
                water += maxRight - height[right];  // Water trapped on right
            }
            right--;
        }
    }
    return water;
}