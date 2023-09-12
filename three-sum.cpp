#include "bits/stdc++.h"

using namespace std;

void twoSum(vector<int> &nums, vector<vector<int>> &ans, int start, size_t end, int target, int value) {
    while (start < end) {
        auto s = nums[start] + nums[end];
        if (s == target) {
            vector<int> res{value, nums[start], nums[end]};
            ans.push_back(res);
            while (start < end && nums[start] == nums[start + 1]) {
                start++;
            }
            start++;
            while (start < end && nums[end] == nums[end - 1]) {
                end--;
            }
            end--;
        } else if (s < target) {
            start++;
        } else {
            end--;
        }
    }
}

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    size_t s = nums.size();
    for (int i = 0; i < s; ++i) {
        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }
        twoSum(nums, ans, i + 1, s - 1, -nums[i], nums[i]);
    }
    return ans;
}

int main() {
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    auto res = threeSum(nums);
    for (const auto &v: res) {
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}