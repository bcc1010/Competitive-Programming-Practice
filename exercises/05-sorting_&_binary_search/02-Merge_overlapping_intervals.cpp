#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::pair;

vector<pair<int, int>> mergeOverlappingIntvls(vector<pair<int, int>> intervals) {
    std::sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> res;

    for (const auto& [start, end] : intervals) {
        if (res.empty() || start > res.back().second) {
            res.push_back({start, end});
        } else {
            res.back().second = std::max(end, res.back().second);
        }
    }
    return res;
}

void outputRes(vector<pair<int, int>> res) {
    std::cout << '[';
    bool first = true;
    for (const auto& curr : res) {
        if (first) {
            first = false;
        } else {
            std::cout << ',';
        }
        std::cout << '[' << curr.first << ',' << curr.second << ']';
    }
    std::cout << ']' << '\n';
}

int main() {
    vector<pair<int, int>> v1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<pair<int, int>> v2 = {{1, 4}, {4, 5}};
    vector<pair<int, int>> v3 = {{1, 4}, {2, 3}};
    vector<pair<int, int>> res1 = mergeOverlappingIntvls(v1);
    vector<pair<int, int>> res2 = mergeOverlappingIntvls(v2);
    vector<pair<int, int>> res3 = mergeOverlappingIntvls(v3);
    outputRes(res1);
    outputRes(res2);
    outputRes(res3);
}