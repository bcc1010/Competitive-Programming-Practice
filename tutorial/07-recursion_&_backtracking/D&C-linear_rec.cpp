#include <string>
using std::string;

// Reverse a string recursively
void reverse(string& s, int left, int right) {
    if (left >= right) return;
    std::swap(s[left], s[right]);
    reverse(s, left + 1, right - 1);
}