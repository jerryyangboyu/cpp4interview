#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int> &prices) {
        int historicalLowest = INT_MAX;
        int historicalBestDeal = INT_MIN;
        for (auto price: prices) {
            historicalLowest = min(historicalLowest, price);
            historicalBestDeal = max(historicalBestDeal, price - historicalLowest);
            cout << "lowest: " << historicalLowest << " best deal: " << historicalBestDeal << endl;
        }
        return historicalBestDeal;
    }
};

int main() {
    auto prices = vector<int>{7, 1, 5, 3, 6, 4};
    auto result = Solution::maxProfit(prices);
    cout << "the result is: " << result << endl;
}
