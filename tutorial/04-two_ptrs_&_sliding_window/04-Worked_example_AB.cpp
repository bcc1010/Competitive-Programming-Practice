// Given a string containing only 'A' and 'B', find the length of the longest
// substring containing at most one 'B'.

// Recognition trigger: variable sliding window
//      Pattern: expand, shrink, update.

#include <iostream>
#include <string>
using std::string;

int longestSubstrWithMaxOneB(const string& str) {
    int countB = 0;
    int left = 0;
    int curr = 0;
    int maxSubstrLen = 0;
    while (curr < (int)str.size()) {
        // Expand
        if (str[curr] == 'B') {
            countB++;
        }

        // Shrink
        while (countB > 1 && left <= curr) {
            if (str[left] == 'B') {
                countB--;
            }
            left++;
        }

        // Update
        maxSubstrLen = std::max(curr - left + 1, maxSubstrLen);

        curr++;
    }
    return maxSubstrLen;
}

int main() {
    std::cout << longestSubstrWithMaxOneB("BAABBAAAB");
}