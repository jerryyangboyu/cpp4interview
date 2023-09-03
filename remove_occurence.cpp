#include <string>
#include <iostream>

using namespace std;

string removeOccurrences(string s, const string &part) {
    auto i = s.find(part);
    auto sz = part.size();
    while (i != string::npos) {
        s.erase(i, sz);
        i = s.find(part);
        cout << s << endl;
    }
    return s;
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    string result = removeOccurrences(s, part);
    cout << result << endl;
}
