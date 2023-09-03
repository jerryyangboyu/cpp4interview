#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m), c(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i] >> c[i];
    }

    // 对商品和优惠券进行排序
    sort(a.begin(), a.end(), greater<int>());
    vector<pair<int, int>> coupons;
    for (int i = 0; i < m; i++) {
        coupons.push_back({b[i], c[i]});
    }
    sort(coupons.begin(), coupons.end(), greater<pair<int, int>>());

    int ans = 0;
    int j = 0;

    // 从最高价的商品开始尝试匹配最合适的优惠券
    for (int i = 0; i < n; i++) {
        while (j < m && coupons[j].first > a[i]) {
            j++;
        }

        if (j < m) {
            ans += a[i] - coupons[j].second;
            j++;
        } else {
            ans += a[i];
        }
    }

    cout << "最低花销是: " << ans << endl;

    return 0;
}
