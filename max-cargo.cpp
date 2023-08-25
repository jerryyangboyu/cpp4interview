/*
 * @Author: Jerry
 * @Date: 2023/8/25.
*/

#include <iostream>
#include <vector>

using namespace std;

int solveCargo(int maxCargo, vector<vector<int>> &cargos) {
    sort(cargos.begin(), cargos.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
    });
    auto dp = vector<int>(maxCargo, 0);
    for (auto cargo: cargos) {
        cout << "cargo: ";
        copy(cargo.begin(), cargo.end(), ostream_iterator<int>(cout, " "));

        cout << " dp: ";
        copy(dp.begin(), dp.end(), ostream_iterator<int>(cout, " "));
        cout << endl;

        auto previous_best = *max_element(dp.begin(), dp.begin() + cargo[0] + 1);
        auto yield = cargo[1] - cargo[0] + cargo[2];

        cout << previous_best << endl;

        dp[cargo[1]] = max(previous_best, previous_best + yield);
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    auto input = vector<vector<int>>{
            {1,  6,  1},
            {3,  10, 2},
            {10, 12, 3},
            {12, 15, 2},
            {13, 18, 1}
    };

    auto result = solveCargo(20, input);

    cout << "result is: " << result << endl;

    return 0;
}