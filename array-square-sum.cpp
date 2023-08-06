#include "iostream"
#include "cmath"

using namespace std;

int main() {
    int m;
    double n, result;
    while (cin >> n >> m) {
        result = n;
        for (int i = 0; i < m - 1; ++i) {
            n = sqrt(n);
            result += n;
        }
        printf("%.2f\n", result);
    }
}
