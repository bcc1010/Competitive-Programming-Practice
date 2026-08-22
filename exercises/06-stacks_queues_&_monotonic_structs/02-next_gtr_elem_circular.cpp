#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::stack;

vector<int> findCircArrayGreaters(const vector<int>& arr) {
    int n = (int)arr.size();
    vector<int> res(n, -1);
    stack<int> stk;

    for (int i = 0; i < 2 * n; i++) {
        while (!stk.empty() && arr[stk.top()] < arr[i % n]) {
            res[stk.top()] = arr[i % n];
            stk.pop();
        }
        if (i < n) stk.push(i);
    }
    return res;
}

int main() {
    auto print = [](const vector<int>& v) {
        for (int x : v) std::cout << x << ' ';
        std::cout << '\n';
    };

    print(findCircArrayGreaters({1, 2, 1}));
    print(findCircArrayGreaters({5, 4, 3, 2, 1}));
    print(findCircArrayGreaters({1, 2, 3, 4, 3}));
}