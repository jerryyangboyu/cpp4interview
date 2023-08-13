#include <vector>
#include <iostream>

using namespace std;

int getUmbrellas(int requirements, const vector<int>& sizes) {
    auto s = (int)size(sizes); // assume all sizes are integer ranges
    auto dp = vector<int>(requirements + 1, requirements + 1);
    dp[0] = 0;
    for (int i = 1; i < s + 1; ++i) {
        for (int j = i; j < requirements + 1; ++j) {
            dp[j] = min(dp[j], dp[j - i] + 1);
        }
    }
    return dp[requirements] == requirements + 1 ? -1 : dp[requirements];
}

int main() {
    int requirements, size_count;
    cin >> requirements >> size_count;
    vector<int> sizes;
    for (int i = 0; i < size_count; ++i) {
        int size;
        cin >> size;
        sizes.push_back(size);
    }
    cout << getUmbrellas(requirements, sizes);
}
