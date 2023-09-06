#include "bits/stdc++.h"

using namespace std;

vector<string> bitPattern(vector<int> &nums) {
    if (nums.size() < 2) return {"", ""};
    auto s = nums.size();
    string s1(s, '0');
    string s2(s, '0');
    map<int, bool> prev_nums;

    for (int i = 0; i < s; ++i) {
        if (prev_nums.contains(nums[i])) {
            s1[i] = '1';
        } else {
            prev_nums[nums[i]] = true;
        }
    }
    prev_nums.clear();

    for (int j = s - 1; j >= 0; --j) {
        if (prev_nums.contains(nums[j])) {
            s2[j] = '1';
        } else {
            prev_nums[nums[j]] = true;
        }
    }

    return {s1, s2};
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 1};
    auto r = bitPattern(arr);
    cout << r[0] << " " << r[1] << endl;
    return 0;
}