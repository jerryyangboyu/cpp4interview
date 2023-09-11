#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int findMaxSubsequenceLength(const vector<int>& arr, int m) {
    int n = arr.size();

    // Create a difference array: diff[i] = arr[i] - m
    vector<int> diff(n);
    for (int i = 0; i < n; ++i) {
        diff[i] = arr[i] - m;
    }

    // Compute prefix sums: prefix[i] = diff[0] + ... + diff[i]
    vector<int> prefix(n+1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i+1] = prefix[i] + diff[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int sum = prefix[j+1] - prefix[i];
            if (sum > 0) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {9, 1, 9, 1, 9};
    int m = 5;
    cout << "Max length of subsequence: " << findMaxSubsequenceLength(arr, m) << endl;
    return 0;
}
