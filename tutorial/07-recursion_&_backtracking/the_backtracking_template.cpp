// void backtrack(/* current state, constraints, results */) {
//     // 1. BASE CASE - have we reached a complete solution?
//     if (isSolution(currentState)) {
//         results.push_back(currentState);
//         return;
//     }

//     // 2. ITERATE over all possible choices at this step
//     for (auto& choice : getPossibleChoices(currentState)) {

//         // 3. CHECK - is this choice valid? (pruning)
//         if (!isValid(choice, currentState)) continue;

//         // 4. MAKE THE CHOICE - modify state
//         makeChoice(choice, currentState);

//         // 5. RECURSE - explore further with this choice made
//         backtrack(currentState, constraints, results);

//         // 6. UNDO the choice - restore state (backtrack)
//         undoChoice(choice, currentState);
//     }
// }

// // The UNDO step is what makes this backtracking.
// // After exploring all paths that include a particular choice, you undo that
// // choice and try the next one.
// // The state is always restored back to what it was before the choice was made.

// // Think of it as exploring a tree:
// //      Each node is a partial solution.
// //      Each edge is a choice.
// //      Leaves are complete solutions (or dead ends).
// //      Backtracking means returning from a node and trying a different edge.

// // WAY TO REMEMBER:
// // Backtracking is BICHECHORU
// // B    ase case
// // I    teration
// // CHE  ck
// // CHO  ice
// // R    ecurse
// // U    ndo