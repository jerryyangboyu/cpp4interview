#include <iostream>
#include <numeric>

using namespace std;

int main() {
    unsigned int a = 1;
    unsigned int b = 89;
    a = a - b;
    std::cout << a << endl;
    std::cout << std::numeric_limits<unsigned int>::max() << endl;
    cout << std::numeric_limits<unsigned int>::max() - b + 2;
}
