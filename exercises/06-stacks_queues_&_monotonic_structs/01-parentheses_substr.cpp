#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using std::stack;
using std::string;

int findLongestParenSbstr(string str) {
    stack<int> stk;
    stk.push(-1);
    int maxLen = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();

            if (stk.empty()) {
                stk.push(i);
            } else {
                maxLen = std::max(maxLen, i - stk.top());
            }
        }
    }
    return maxLen;
}

int main() {
    string test1 = "(()";
    string test2 = ")()())";
    string test3 = "";
    string test4 = "()()";
    std::cout << findLongestParenSbstr(test1) << '\n';
    std::cout << findLongestParenSbstr(test2) << '\n';
    std::cout << findLongestParenSbstr(test3) << '\n';
    std::cout << findLongestParenSbstr(test4) << '\n';
}