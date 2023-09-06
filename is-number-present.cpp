#include "bits/stdc++.h"

using namespace std;

vector<string> bitPattern(vector<int> &nums) {
    if (nums.size() < 2) {
        return {"", ""};
    }
    auto s = nums.size();
    string s1(s, '0');
    string s2(s, '0');
    for (int i = 0; i < s; ++i) {
        bool stop = false;
        for (int j = 0; j < i && !stop; ++j) {
            if (nums[j] == nums[i]) {
                s1[i] = '1';
                stop = true;
            }
        }
        stop = false;
        for (int k = i + 1; k < s && !stop; ++k) {
            if (nums[k] == nums[i]) {
                s2[i] = '1';
                stop = true;
            }
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