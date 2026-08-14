#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;

// Two sum on a sorted array
std::pair<int, int> twoSum(const vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return {left, right};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return {-1, -1};
}

// Three sum on an array
vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = (int)nums.size();

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate values for the fixed element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}

// Fast and slow
void example(const vector<int>& arr) {
    int slow = 0;
    for (int fast = 0; fast < (int)arr.size(); fast++) {
        if (shouldKeep(arr[fast])) {
            arr[slow] = arr[fast];      // Write valid element to slow position
            slow++;
        }
    }
}

// Remove duplicates from sorted array
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int slow = 0;
    for (int fast = 1; fast < (int)nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1;
}
// Note that this technique only works on a sorted array.

// Remove element in place
int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}

// Move zeros to end
void moveZeros(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); fast++) {
        if (nums[fast] != 0) {
            nums[slow] = nums[fast];
        }
    }

    for (int i = slow + 1; i < (int)arr.size(); i++) {
        nums[i] = 0;
    }
}

// Configuration with two arrays, two sequences
// Merge two sorted arrays into one sorted array
vector<int> mergeSorted(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;

    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] <= b[j]) {
            res.push_back(a[i++]);
        } else {
            res.push_back(b[j++]);
        }
    }

    // Append remaining elements from whichever array is not exhausted
    while (i < (int)a.size() res.push_back(a[i++]));
    while (j < (int)b.size() res.push_back(b[j++]));

    return res;
}

// Is s a subsequence of t?
bool isSubsequence(const string& s, const string& t) {
    int i = 0, j = 0;

    while (i < (int)s.size() && j < (int)t.size()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return i == (int)s.size();
})

// Sliding window problems fall into two categories, and you need to identify
// which one you are dealing with before writing any code.
//      1.  Fixed window size (window size k is given, you slide a window
//          of size k across the array).
//      2.  You are looking for the longest or shortest window satisfying some
//          constraint. The window grows and shrinks dynamically.



// FIXED WINDOW TEMPLATE
int n = (int)arr.size();
if (n < k) return -1;       // Edge case - array smaller than window

// Build the first window
// Process arr[0..k-1]
for (int i = 0; i < k; i++) {
    // add arr[i] to window state
}

// Record initial result
// best = initialWindowResult

// Slide the window
for (int i = k; i < n; i++) {
    // Add arr[i]       new right element enters
    // Remove arr[i-k]  old left element leaves
    // Update result
}



// VARIABLE WINDOW TEMPLATE
int left = 0;
// Initialise window state

for (int right = 0; right < n; right++) {
    // 1.   EXPAND      add arr[right] to window state
    // 2.   SHRINK      while window violates constraint
    while (/* constraint violated*/) {
        // Remove arr[left] from window state
        left++;
    }

    // 3.   UPDATE      window [left, right] is now valid
    best = std::max(best, right - left + 1);    // For longest
    // OR
    best = std::min(best, right - left + 1);    // For shortest
}


// Exactly k = at most k - at most (k - 1)
int exactlyK(const vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

int atMostK(const vector<int>& nums, int k) {
    unordered_map<int, int> window;
    int left = 0, count = 0;

    for (int right = 0; right < (int)nums.size(); right++) {
        window[nums[right]]++;
        while ((int)window.size() > k) {
            int leftElem = nums[left];
            window[leftElem]--;
            if (window[leftElem] == 0) window.erase(leftElem);
            left++;
        }
        count += right - left + 1;
    }
    return count;
}

void sortColours(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = (int)nums.size() - 1;

    while (mid < high) {
        if (nums[mid] == 0) {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}