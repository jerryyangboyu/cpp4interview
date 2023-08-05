#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    /**
     * Greedy algorithm
     * @param prices
     * @return
     */
    static int maxProfit(vector<int> &prices) {
        int bestPrice = 0;
        for (int i = 1; i < size(prices); ++i) {
            if (prices[i - 1] < prices[i])
                bestPrice += prices[i] - prices[i - 1];
        }
        return bestPrice;
    }
};

int main() {
    auto prices = vector<int>{7, 1, 5, 3, 6, 4};
    auto result = Solution::maxProfit(prices);
    cout << "the result is: " << result << endl;
}
