#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

using namespace std;

float evaluate_mark(int except_idx, const vector<int> &v) {
    int sumn = 0;
    int maxn = numeric_limits<int>::min();
    int minn = numeric_limits<int>::max();
    for (int i = 0; i < v.size(); ++i) {
        if (i == except_idx) {
            continue;
        }
        int numn = v[i];
        maxn = max(maxn, numn);
        minn = min(minn, numn);
        sumn += numn;
    }
    return (sumn - maxn - minn) / (v.size() - 3);
}

int main() {
    int n, ai, bi;
    vector<int> scorea(n, 0);
    vector<int> scoreb(n, 0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ai >> bi;
        scorea[i] = ai;
        scoreb[i] = bi;
    }

    copy(scorea.begin(), scorea.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(scoreb.begin(), scoreb.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    for (int j = 0; j < n; ++j) {
        auto sa = evaluate_mark(j, scorea);
        auto sb = evaluate_mark(j, scoreb);
        cout << (sa + sb) / 2 << endl;
    }
}
