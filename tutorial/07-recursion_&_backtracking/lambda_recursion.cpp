#include <functional>
#include <vector>
using std::vector;
using std::function;

vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> curr;

    function<void(int)> backtrack = [&](int start) {
        res.push_back(curr);
        for (int i = start; i < (int)nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(i + 1);
            curr.pop_back();
        }
    };

    backtrack(0);
    return res;
}

// The pattern of:
//      FIRST std::function
//      THEN  [&] capture
//      THEN  recursive call
// is the cleanest way of writing backtracking in a self-contained C++ function.