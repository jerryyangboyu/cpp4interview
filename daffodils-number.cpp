#include "iostream"

using namespace std;

int find_and_print_daffodils_number(int min, int max) {
    int count = 0;
    for (int i = min; i <= max; ++i) {
        int a = i / 100;
        int b = i / 10 % 10;
        int c = i % 10;
        if (i == a * a * a + b * b * b + c * c * c) {
            cout << i << " ";
            ++count;
        }
    }
    if (count == 0) {
        cout << "no";
    }
    cout << endl;
    return count;
}

int main() {
    int min, max;
    while (cin >> min >> max) {
        find_and_print_daffodils_number(min, max);
    }
}
