// Problem: given an array of daily temperatures, return an array where each
// element is the number of days you have to wait until a warmer temperature.
// If no warmer day exists, return 0.
#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::stack;

vector<int> dailyTemperatures(const vector<int>& temps) {
    int n = (int)temps.size();
    vector<int> res(n, 0);
    stack<int> stk;

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && temps[stk.top()] < temps[i]) {
            int idx = stk.top();
            stk.pop();
            res[idx] = i - idx;
        }
        stk.push(i);
    }
    return res;
}