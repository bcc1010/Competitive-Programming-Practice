#include <vector>
#include <deque>
using std::vector;
using std::deque;

vector<int> slidingWindowMax(const vector<int>& nums, int k) {
    deque<int> dq;  // Stores indices
    vector<int> res;
    int n = (int)nums.size();

    for (int i = 0; i < n; i++) {
        // Remove indices outside the curr window from the front
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove indices whose values are smaller than nums[i] from the back
        // They can never be the maximum - nums[i] is larger and more recent
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        // Window is fully formed once i >= k - 1
        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);        // Front is always max
        }
    }
    return res;
}