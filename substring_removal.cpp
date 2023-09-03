#include "bits/stdc++.h"

using namespace std;

int getMinLength(const string &seq) {
    stack<char> s;
    for (const char c: seq) {
        if (c == 'B' && !s.empty()) {
            s.pop();
        } else {
            s.push(c);
        }
    }
    return (int)s.size();
}

int main() {
    string s = "BABBA";
    cout << getMinLength(s) << endl;
}