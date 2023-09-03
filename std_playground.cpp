#include "bits/stdc++.h"

using namespace std;

// compile time infer
template<typename T, size_t N>
void printArrayInfo(T (&_array)[N]) {
    std::cout << "Element type: " << typeid(T).name() << std::endl;
    std::cout << "Number of elements: " << N << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << _array[i] << " ";
    }
    std::cout << std::endl;
}

string m_hash(string &s) {
    string rs(26, '0');
    for (const char c: s) {
       rs[c - 'a'] += 1;
    }
    return rs;
}

int main() {
    auto p = (int *) ::operator new(10 * sizeof(int));
    ::operator delete(p);

    int array[]{1, 3, 5, 2, 6, 7};
    printArrayInfo(array);

    std::vector<int> a(10, 1);
    auto b = a;
    b[0] = 0;
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::copy(b.begin(), b.end(), std::ostream_iterator<int>(std::cout, " "));

    auto c = std::move(a);
    c[0] = 0;
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::copy(b.begin(), b.end(), std::ostream_iterator<int>(std::cout, " "));

    const int *const p1 = new int[1];

    const char *const authorName = "Schott Meyers";

    std::deque<int> q;

    std::string s(20, 'a');
    s[3] += 4;
    std::cout << s;

    string s1 = "abc";
    cout << m_hash(s1) << endl;

    string s2 = "alcohol";
    sort(s2.begin(), s2.end());
    cout << s2 << endl;
}