#include <vector>
using std::vector;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = (int)arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int leftMostOccurrence(const vector<int>& arr, int target) {
    int left = 0;
    int right = (int)arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;        // Keep searching LEFT!!
            // right = mid + 1;     // or, alt, keep searching right!!
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

// Binary search on a rotated sorted array
// KEY INSIGHT: Even in a sorted array, at least one half of the array (left or
//      right of mid) is always sorted. You can determine which half is sorted
//      by comparing arr[left] with arr[mid], and then check whether the
//      target falls in the sorted half.
int searchRotated(const vector<int>& arr, int target) {
    int left = 0;
    int right = (int)arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;

        // Determine which half is sorted
        if (arr[left] <= arr[mid]) {
            // Left half [left..mid] is sorted
            if (arr[left] <= target && target < arr[mid]) {
                right = mid - 1;        // Target is in sorted left half
            } else {
                left = mid + 1;         // Target must be in the right half
            }
        } else {
            // Right half [mid..right] is sorted
            if (arr[mid] < target && target <= arr[right]) {
                left = mid + 1;         // Target is in the sorted right half
            } else {
                right = mid - 1;        // Target must be in the left half
            }
        }
    }
    return -1;
}

// The most important and underused application of binary search is that many
// problems (even those not mentioning a sorted array) can be solved with
// binary search, by searching on the space of possible answers instead of the
// input array.