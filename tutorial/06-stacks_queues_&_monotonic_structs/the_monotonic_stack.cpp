// // Monotonic increasing stack - bottom to top is increasing
// std::stack<int> stk;
// std::vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};

// for (int x : nums) {
//     // Pop elements that are >= x (they violate increasing order)
//     while (!stk.empty() && stk.top() >= x) {
//         stk.pop();
//     }
//     stk.push(x);
// }
// // Stack contains only 1, 2, 6