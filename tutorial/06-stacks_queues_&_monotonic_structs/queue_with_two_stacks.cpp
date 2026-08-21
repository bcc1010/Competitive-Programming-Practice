#include <stack>
using std::stack;

class MyQueue {
    stack<int> inbox;   // New elements go here
    stack<int> outbox;  // Old elements leave here

    void transfer() {
        if (outbox.empty()) {           // Don't bury old ones!
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
    }

public:
    void push(int x) {
        inbox.push(x);
    }

    int pop() {
        transfer();
        int val = outbox.top();
        outbox.pop();
        return val;
    }

    int peek() {
        transfer();
        return outbox.top();
    }

    bool empty() {
        return inbox.empty() && outbox.empty();
    }
};