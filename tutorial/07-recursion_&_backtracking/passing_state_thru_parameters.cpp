#include <vector>
using std::vector;

void backtrack(int start, vector<int>& current, vector<int>& nums,
               vector<vector<int>>& res) {
    // current holds the partial solution built so far
    res.push_back(current);

    for (int i = start; i < (int)nums.size(); i++) {
        current.push_back(nums[i]);
        backtrack(i + 1, current, nums, res);
        current.pop_back();
    }
}

// When passing the partial solution, always pass by REFERENCE and never by
// value. You are modifying it in place and undoing modifications. Passing by
// value would make a copy at every level, which is both slow and incorrect
// (the undo step would not affect the caller's copy).