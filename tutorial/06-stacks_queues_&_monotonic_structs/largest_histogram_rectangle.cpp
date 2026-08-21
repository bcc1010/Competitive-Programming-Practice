// #include <vector>
// #include <stack>
// using std::vector;
// using std::stack;

// int largestHistogramRectangle(const vector<int> heights) {
//     stack<int> stk;
//     int best = 0;
//     int n = (int)heights.size();

//     for (int i = 0; i <= n; i++) {
//         // Use height 0 as a sentinel value at the end to force popping
//         int currHeight = (i == n) ? 0 : heights[i];
        
//         while (!stk.empty() && heights[stk.top()] > currHeight) {
//             int height = heights[stk.pop()];
//             stk.pop();

//             // Width: from the new stack top to current position
//             int width = stk.empty() ? i : i - stk.top() - 1;
//             best = std::max(best, height * width);
//         }
//         stk.push(i);
//     }
//     return best;
// }