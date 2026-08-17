// PROBLEM
//   You have packages with weights [1, 2, 3, 4, 5, 6, 7, 8, 9, 10].
//   You must ship all packages in 'days' days.
//   Packages must be shipped in order. 
//   Find the minimum ship capacity such that all packages can be shipped within
//      'days' days.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using std::vector;

// TO SOLVE THIS PROBLEM:
//      Notice that this is a max/min problem which uses a monotonic search space.
//      This means that we can apply the binary search on the answer technique.
//      Determine our lowest possible: the max weight.
//      Determine our highest possible: the total sum.
//      Determine how to calculate the condition required for success.
//      Fill in with the memorised template.

// Helper - condition
bool canShip(const vector<int>& weights, int days, int capacity) {
    int daysNeeded = 1;
    int currLoad = 0;

    for (int w : weights) {
        if (currLoad + w > capacity) {
            daysNeeded++;
            currLoad = 0;
        }
        currLoad += w;
    }
    return daysNeeded <= days;
}

// Key algorithm
int findMinShippingCapacity(const vector<int>& weights, int days) {
    int lo = *std::max_element(weights.begin(), weights.end());
    int hi = std::accumulate(weights.begin(), weights.end(), 0);
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (canShip(weights, days, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

// Testing
int main() {
    vector<int> ex_weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ex_days = 5;
    std::cout << findMinShippingCapacity(ex_weights, ex_days);
}