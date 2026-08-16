// PROBLEM: Kth Smallest in a Sorted Matrix

// Given an nxn matrix where each row and each column is sorted, find the kth
// smallet element.
#include <vector>
using std::vector;

int kthSmallest(const vector<vector<int>>& matrix, int k) {
    int n = (int)matrix.size();
    int lo = matrix[0][0];
    int hi = matrix[n-1][n-1];

    auto countLessEqual = [&](int mid) {
        int count = 0;
        int row = n - 1;
        int col = 0;
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }
        return count;
    };

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (countLessEqual(mid) >= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
}