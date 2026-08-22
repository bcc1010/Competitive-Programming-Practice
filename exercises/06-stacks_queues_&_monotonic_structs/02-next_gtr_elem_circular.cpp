#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::stack;

vector<int> findCircArrayGreaters(const vector<int>& arr) {
    stack<int> stk;      // indices
    vector<int> working_res(arr.size(), -1);
    vector<int> repeat_arr;
    repeat_arr.reserve(arr.size() * 2);
    repeat_arr.insert(repeat_arr.end(), arr.begin(), arr.end());
    repeat_arr.insert(repeat_arr.end(), arr.begin(), arr.end());
    for (int i = 0; i < repeat_arr.size(); i++) {
        while (!stk.empty() && repeat_arr[stk.top()] < repeat_arr[i]) {
            working_res[i] = repeat_arr[stk.top()];
            stk.pop();
        }
        stk.push(i);
    }
    vector<int> res;
    res.reserve(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        res[i] = working_res[i];
    };
    return res;
}

int main() {
    vector<int> v1 = {1, 2, 1};
    vector<int> v2 = {5, 4, 3, 2, 1};
    vector<int> v3 = {1, 2, 3, 4, 3};
    vector<int> r1 = findCircArrayGreaters(v1);
    vector<int> r2 = findCircArrayGreaters(v2);
    vector<int> r3 = findCircArrayGreaters(v3);
    for (int num : r1) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
    for (int num : r2) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
    for (int num : r3) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}