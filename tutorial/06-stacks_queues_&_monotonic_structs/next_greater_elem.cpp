// Problem: for each element in an array, find the next element to its right
// that is greater than it. If none exists, return -1.
#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::stack;

vector<int> nextGreaterElement(const vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> res(n, -1);     // Default = -1
    stack<int> stk;             // Stores indices, not values

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && nums[stk.top()] < nums[i]) {
            res[stk.top()] = nums[i];   // nums[i] is the next greater element
            stk.pop();
        }
        stk.push(i);        // Push index - so we can fill result array
    }
    return res;
}
