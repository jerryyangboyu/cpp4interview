#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    /**
     * Greedy algorithm with 2 steps
     * @param prices
     * @return
     */
    static int maxProfit(vector<int> &prices) {
        int bestBuy1 = INT_MAX, bestBuy2 = INT_MAX;
        int bestSell1 = INT_MIN, bestSell2 = INT_MIN;
        for (auto price: prices) {
            // make the best profit initially
            bestBuy1 = min(bestBuy1, price);
            bestSell1 = max(bestSell1, price - bestBuy1);
            // make sure that the second transaction do not lose money
            // do not spend all you money on one thing to cause deficit, earn money incrementally
            bestBuy2 = min(bestBuy2, price - bestSell1);
            bestSell2 = max(bestSell2, price - bestBuy2);
        }
        return bestSell2;
    }
};

int main() {
    auto prices = vector<int>{7, 1, 5, 3, 6, 4};
    auto result = Solution::maxProfit(prices);
    cout << "the result is: " << result << endl;
}
