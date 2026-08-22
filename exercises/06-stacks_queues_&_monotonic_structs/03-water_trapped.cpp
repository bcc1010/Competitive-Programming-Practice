#include <iostream>
#include <vector>
using std::vector;

int calcTrappedWater(const vector<int>& heights) {
    int left = 0;
    int right = (int)heights.size() - 1;
    int maxLeft = 0;
    int maxRight = 0;
    int water = 0;

    while (left < right) {
        if (heights[left] < heights[right]) {
            if (heights[left] >= maxLeft) {
                maxLeft = heights[left];
            } else {
                water += maxLeft - heights[left];
            }
            left++;
        } else {
            if (heights[right] >= maxRight) {
                maxRight = heights[right];
            } else {
                water += maxRight - heights[right];
            }
            right--;
        }
    }
    return water;
}

int main() {
    std::cout << calcTrappedWater({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << '\n';
    std::cout << calcTrappedWater({4, 2, 0, 3, 2, 5}) << '\n';
    std::cout << calcTrappedWater({3, 0, 3}) << '\n';
}