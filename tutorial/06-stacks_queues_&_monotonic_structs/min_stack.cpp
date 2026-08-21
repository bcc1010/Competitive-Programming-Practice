#include <stack>
using std::stack;

class MinStack {
    stack<int> data;
    stack<int> minData;     // Tracks minimum at each level

public:
    void push(int val) {
        data.push(val);
        int currMin = minData.empty() ? val : std::min(val, minData.top());
        minData.push(currMin);
    }

    void pop() {
        data.pop();
        minData.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minData.top();
    }
};