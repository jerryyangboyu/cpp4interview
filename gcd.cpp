/*
 * @Author: Jerry
 * @Date: 2023/8/25.
*/


#include <iostream>

using namespace std;

int gcd(int x, int y) {
    while (y != 0) {
        int prev_x = x;
        x = y;
        y = prev_x % y;
    }
    return x;
}

int main() {
    cout << "The gcd of 27 and 972 is: " << gcd(27, 972) << endl;
}
