// Problem: Merge overlapping intervals
// Sorted by start time: O(n log n) - process intervals in order
#include <vector>
#include <algorithm>
using std::vector;
using std::pair;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());      // Sort by start time
    vector<pair<int, int>> result;

    for (const auto& [start, end] : intervals) {
        if (result.empty() || result.back().second < start) {
            result.push_back({start, end});     // No overlap - add new interval
        } else {
            result.back().second = std::max(result.back().second, end);
        }
    }
    return result;
}