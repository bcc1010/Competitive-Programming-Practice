#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

bool canEat(const vector<int>& piles, int h, int k) {
    int hNeeded = 0;
    for (int p : piles) {
        hNeeded += (p + k - 1) / k;
    }
    return hNeeded <= h;
}

int findMinimumBananaRate(const vector<int>& piles, int h) {
    // Recognition trigger: binary search on the answer
    int lo = 1;
    int hi = *std::max_element(piles.begin(), piles.end());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (canEat(piles, h, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    vector<int> v1 = {3, 6, 7, 11};
    vector<int> v2and3 = {30, 11, 23, 4, 20};     
    int h1 = 8;
    int h2 = 5;
    int h3 = 6;
    std::cout << findMinimumBananaRate(v1, h1) << '\n';
    std::cout << findMinimumBananaRate(v2and3, h2) << '\n';
    std::cout << findMinimumBananaRate(v2and3, h3) << '\n';
}