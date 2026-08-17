// // Find minimum value satisfying condition
// int binarySearchAnswer(int lo, int hi) {
//     while (lo < hi) {       // Strict equality
//         int mid = lo + (hi - lo) / 2;
//         if (condition(mid)) {
//             hi = mid;       // mid might be the answer, so keep it!
//         } else {
//             lo = mid + 1;   // mid definitely is not the answer
//         }
//     }
//     return lo;
// }