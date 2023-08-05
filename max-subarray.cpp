#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    static int maxSubArray(vector<int> &nums) {
        auto dp = vector<int>(size(nums));
        dp[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < size(nums); ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};

int main() {
    auto arr = vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto result = Solution::maxSubArray(arr);
    cout << "the result is: " << result;
}
